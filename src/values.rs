use std::collections::HashMap;

#[derive(Clone, Debug)]
pub enum Type {
    Simple(String),
    Object(String, Vec<ObjectField>),
    Generic(String, Vec<String>),
    GenericInstance(Box<Type>, Vec<Type>)
}

#[derive(Clone, Debug)]
pub struct ObjectField {
    pub name: String,
    pub typ: Type
}


#[derive(Clone, Debug)]
#[allow(dead_code)]
pub enum Value {
    Int(i64, Type),
    Text(String, Type),
    Name(String, Type),
    List {items: Vec<Value>, typ: Type} ,
    BuiltinFunction(String, Type),
    PropertyMethod(String, Type),
    Stream(String, Type),
    Object(Vec<Value>, Type),
    Error(String, Type)
}

// #[derive(Clone)]
pub struct StreamData {
    pub files: std::fs::ReadDir,
    pub i: usize,
    pub init_ok: bool,
    pub error_message: String
}

// #[derive(Clone, Debug)]
// pub struct LangStream {
//     pub name: String,
//     pub typ: Type
// }

#[derive(Clone)]
pub struct LangStreamImpl {
    // data: &mut HashMap<String, Value>
    pub init: fn(data: &mut StreamData), 
    pub generate_next: fn(data: &mut StreamData) -> Option<Value>
}

impl Value {
    pub fn get_field(&self, name: &str) -> Option<Value> {
        if let Value::Object(field_values, typ) = self {
            let index_option = typ.get_field_index(name);
            if let Some(index) = index_option {
                Some(field_values[index].clone())
            } else {
                None
            }
        } else {
            None
        }
    }

    pub fn get_string(&self) -> Option<String> {
        if let Value::Text(text, typ) = self {
            Some((*text).clone())
        } else {
            None
        }
    }
}

impl Type {
    fn get_field_index(&self, name: &str) -> Option<usize> {
        if let Type::Object(_, fields) = self {
            for (i, field) in fields.iter().enumerate() {
                // println!("{} {}", &field.name, name);
                if &field.name == name {
                    return Some(i)
                }
            }
        }
        None
    }
}