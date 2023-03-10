mod interpreter;
mod values;
use interpreter::{Interpreter, TextRenderer};
use std::io::{BufRead, Write, Stdout};
use users::{get_user_by_uid, get_current_uid};

fn on_input_line(interpreter: &mut Interpreter, line: String) {
    // it also renders the result
    // using .renderer
    interpreter.run(line);
}

fn write_prompt(stdout: &mut Stdout) {
    let current_dir = std::env::current_dir().unwrap();
    let user = get_user_by_uid(get_current_uid()).unwrap();
    let user_name = user.name().to_string_lossy();
    write!(*stdout, "{} {} > ", user_name, current_dir.display()).unwrap();
}

fn run_loop() {
    let env = interpreter::initial_env();
    let renderer = TextRenderer {};
    let mut interpreter = Interpreter::init(env, Box::new(renderer));
    let stdin = std::io::stdin();
    let mut line = String::new();
    //stdio "dir\n";
    let mut stdout = std::io::stdout();
    loop {
        write_prompt(&mut stdout);
        stdout.flush().unwrap();

        line.clear();
        stdin.lock().read_line(&mut line).unwrap();
        line = line.trim().to_string();
        // println!("line [{}]", line);

        on_input_line(&mut interpreter, line.to_string());
    }
}

fn main() {
    run_loop();
}
