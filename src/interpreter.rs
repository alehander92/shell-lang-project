use std::collections::HashMap;
// use std::time::{SystemTime, UNIX_EPOCH};
use std::os::unix::fs::MetadataExt;
use crate::values::{Value, Type, ObjectField, LangStreamImpl, StreamData};
use tree_sitter::{Parser, Language, Tree, Node};

extern "C" { fn tree_sitter_project() -> Language; }

pub struct Env {
    values: HashMap<String, Value>    
}

impl Env {
    fn get(&self, name: &str) -> Option<Value> {
        match self.values.get(name) {
            Some(value) => Some((*value).clone()),
            None => None
        }
    }
}


fn simple_type(name: &str) -> Type {
    Type::Simple(name.to_string())
}

fn stream_type(yield_type: Type) -> Type {
    let stream_generic_type = Type::Generic(
        "Stream".to_string(),
        vec!["T".to_string()]);
    
    Type::GenericInstance(
        Box::new(stream_generic_type),
        vec![yield_type])
}

fn stream_value(name: &str, yield_type: Type) -> Value {
    Value::Stream(name.to_string(), stream_type(yield_type))
}

fn list_type(item_type: Type) -> Type {
    let list_generic_type = Type::Generic(
        "List".to_string(),
        vec!["T".to_string()]);
    
    Type::GenericInstance(
        Box::new(list_generic_type),
        vec![item_type])
}

fn list_value(items: Vec<Value>, item_type: Type) -> Value {
    Value::List { items: items, typ: list_type(item_type) }
}

fn error_value(msg: String) -> Value {
    Value::Error(msg, Type::Simple("Error".to_string()))
}

// dir: init: [], readdir; generate: for each file : iterate from dir;
// processes: init: [], get a list of processes in /proc; generate: for each of them: process its files;


// LangStream can index into a table with impls
// or we can have big cases?

// stream dir init{
//     internal = builtin:readdir()
//     i = 0
// } generate_next{
//     if i < internal:length() {
//         yield builtin:to_file(internal[i])
//     } else {
//         return
//     }
// }

// readdir -> Vec<Value::Builtin>
// to_file: Value::Builtin -> Value::Simple TODO Value::Object

fn dir_stream_init(data: &mut StreamData) {
    let res = std::fs::read_dir(".");
    match res {
        Ok(files) => {
            data.files = files;
            data.init_ok = true;
        },
        Err(_e) => {
            data.init_ok = false;
            data.error_message = "read_dir error".to_string();
        }
    };
    data.i = 0usize;
}

fn to_field(name: &str, typ: Type) -> ObjectField {
    ObjectField { name: name.to_string(), typ: typ }
}

fn to_object_type(name: &str, fields: Vec<ObjectField>) -> Type {
    Type::Object(name.to_string(), fields)
}

fn to_object(field_values: Vec<Value>, typ: Type) -> Value {
    Value::Object(field_values, typ)
}

fn to_text_like(text: String, typ: Type) -> Value {
    Value::Text(text, typ)
}

fn to_int_like(i: i64, typ: Type) -> Value {
    Value::Int(i, typ)
}

fn to_file(internal: std::fs::DirEntry) -> Value {
    let typ = to_object_type(
        "File",
        vec![
            to_field("name", simple_type("Name")),
            to_field("size", simple_type("Size")),
            // to_field("user", simple_type("User")),
            // to_field("group", simple_type("Group"))
        ]);
    let metadata = internal.metadata().unwrap();
    // let user = owner().unwrap();
    // o.id(); // 99
    // internal.
    // let datetime = metadata.accessed().unwrap();
    // let timestamp = datetime.duration_since(UNIX_EPOCH).unwrap();
    to_object(
        vec![
            to_text_like(
                internal.file_name().to_str().unwrap().to_string(),
                simple_type("Name")),
            to_int_like(
                metadata.size() as i64,
                simple_type("Size"))
            // to_text_like(
            //     metadata.
            //     simple_type("Date"))
        ],
        typ)
    // Value::Name(internal.file_name().to_str().unwrap().to_string(), simple_type("File"))
}

fn dir_stream_generate_next(data: &mut StreamData) -> Option<Value> {
    let next_file_option = data.files.next();
    match next_file_option {
        Some(next_file) => Some(to_file(next_file.unwrap())),
        None => None
    }
}

static DIR_STREAM_IMPL: LangStreamImpl = LangStreamImpl {
    init: dir_stream_init,
    generate_next: dir_stream_generate_next
};

pub fn initial_env() -> Env {
    let file_type = simple_type("File");
    Env { values: HashMap::from([
            (
                "dir".to_string(),
                stream_value("dir", file_type)
            )
        ])
    }
}

//----------- 

pub trait Renderer {
    // might render in real time? for now
    // return a string and let interpreter print it
    fn render(&self, value: Value, _inline: bool, _top_level: bool) -> String;
}

pub struct TextRenderer {
}

impl Renderer for TextRenderer {
    fn render(&self, value: Value, _inline: bool, _top_level: bool) -> String {
        // "TODO".to_string()
        match value {
            Value::Int(i, _) => {
                format!("{}", i)
             },
            Value::Name(name, _) => {
                format!("{}", name)
            },
            Value::Text(text, _) => {
                format!("\"{}\"", text)
            },
            Value::BuiltinFunction(name, _) => {
                format!("<builtin function {}>", name)
            },
            Value::List { items, typ: _ } => {
                let items_text = items.iter().map(|item| {
                    self.render((*item).clone(), true, false)
                }).collect::<Vec<String>>().join(", ");
                format!("[{}]", items_text)
            },
            Value::Stream(name, _) => {
                format!("<stream {}>", name)
            },
            Value::Object(field_values, typ) => {
                if let Type::Object(name, fields) = typ {
                    let fields_text = fields.iter().zip(field_values).map(|(field, value)| {
                        let value_text = self.render(value, true, false);
                        format!("{}: {}", field.name, value_text)
                    }).collect::<Vec<String>>().join(", ");
                    format!("{}({})", name, fields_text)
                } else {
                    format!("error: type of object not object")
                }
            },
            Value::Error(message, _) => {
                format!("error: {}", message)
            }
        }
    }
}

// -----------

pub struct Interpreter {
    pub env: Env,
    pub renderer: Box<dyn Renderer>,
    parser: Parser,
    source: String
}


impl Interpreter {
    pub fn init(env: Env, renderer: Box<dyn Renderer>) -> Self {
        let language = unsafe { tree_sitter_project() };
        let mut parser = Parser::new();
        parser.set_language(language).unwrap();

        Interpreter { 
            env: env,
            renderer: renderer,
            parser: parser,
            source: String::from("")
        }   
    }

    pub fn run(&mut self, line: String) {
        let res = self.evaluate(line);
        let text = self.renderer.render(res, false, true);
        println!("{}", text);
    }

    fn evaluate(&mut self, source: String) -> Value {
        self.source = source.clone();
        let node_result = self.parse(source);
        match node_result {
            Some(node) => self.evaluate_node(node.root_node()),
            None => error_value("parse error".to_string())
        }
    }

    fn parse(&mut self, source: String) -> Option<Tree> {    
        let res = self.parser.parse(&source, None);
        res
    }
    
    fn evaluate_node(&mut self, node: Node) -> Value {
        println!("  node kind: {:?}", node.kind());
        println!("  node: {:?}", node);
        let res = match node.kind() {
            "source_file" => {
                self.evaluate_node(node.named_child(0).unwrap())
            },
            "name" => {
                self.evaluate_name(
                    node.utf8_text(self.source.as_bytes())
                    .unwrap()
                    .to_string()
                )
            },
            _ => unimplemented!()
        };

        match res {
            Value::Stream(_, _) => {
                self.evaluate_stream(res)
            },
            _ => res
        }
    }

    fn evaluate_stream(&mut self, value: Value) -> Value {
        let stream_impl_map: HashMap<&str, LangStreamImpl> = HashMap::from([
            ("dir", DIR_STREAM_IMPL.clone())
        ]);

        match value {
            Value::Stream(name, Type::GenericInstance(_, types)) => {
                let yield_type = types[0].clone();
                let stream_impl_option = stream_impl_map.get(&*name);
                match stream_impl_option {
                    Some(stream_impl) => {
                        self.stream_to_list(stream_impl, yield_type)
                    },
                    None => {
                        error_value("no stream impl with this name".to_string())
                    }
                }
            },
            _ => {
                error_value("stream had unexpected type".to_string())
            }
        }                
    }

    fn stream_to_list(&mut self, stream: &LangStreamImpl, yield_type: Type) -> Value {
        let mut data = StreamData { 
            files: std::fs::read_dir(".").unwrap(), // TODO
            i: 0usize,
            init_ok: false,
            error_message: String::from("")
        };
            
        let mut res_items: Vec<Value> = vec![];

        (stream.init)(&mut data);
        while true {
            let next_value_option = (stream.generate_next)(&mut data);
            match next_value_option {
                Some(next_value) => {
                    res_items.push(next_value);
                },
                _ => {
                    break;
                }
            }
        }
        list_value(res_items, yield_type)
    }

    fn evaluate_name(&mut self, name: String) -> Value {
        let value_option = self.env.get(&name);
        match value_option {
            Some(Value::BuiltinFunction(_, _)) => {
                // TODO
                unimplemented!();
            },
            Some(value) => {
                value
            },
            None => {
                error_value(format!("{} not found", &name))
            }
        }
    }

    //     match self.evaluate_to_result(line) {
    //         Ok(value) => value,
    //         Err(e) => Value::Error(e, Type::Simple("Error".to_string))
    //     }
    // }

    // fn evaluate_to_result(&mut self, source: String) -> Result<Value, Error> {
        
}
