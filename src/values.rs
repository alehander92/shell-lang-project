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
