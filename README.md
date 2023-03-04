
### credits:

the tree-sitter code is by the tree-sitter authors.

the tree-sitter parser.c code is auto-generated by tree-sitter.


### plan:

a scripting language/shell language for the os(for now linux).

the filesystem, processes and resources are represented as normal program values, native for the language. they have specific types and structure.

for example: 

files are represented as values with different methods
and their paths as variable names(and folders as namespaces).
Otherwise they are the sames as other variables.

```
> a.rs
<Rust file>
> a.rs:raw
fn content() {
}
> b.rs = a.rs
<copied a.rs to b.rs>
> b.rs <- a.rs
<moved a.rs to b.rs>
> c.rs = File("fn example() {}")
<Rust file>
> a_normal_variable = 5
5
```

```
> dir
// List<File>
----------------------------------------
| index | name      | size | typ       |
----------------------------------------
| 0     | a.rs      | 50B  | Rust file
| 1     | README.md | 100B | Markdown  |
----------------------------------------
> dir[0]:size
// ByteSize 
50B
> dir:map(:name)
// List<Name>
---------------------|
| index | value      |
---------------------
| 0     | a.rs       |
| 1     | README.md  |
----------------------
```

We can have different values: numbers, strings, booleans, objects, lists, maps, files, functions and special cases, streams.

Streams are a bit more special: they represent streams of resources like files or processes or network events. Functions/methods applied to them are relatively close to the concept of pipes in most shells.

examples can be 

`dir` for files
`processes` for processes

Here `processes` is a stream on which one can call
functions/methods 
```
> processes:sort(:cpu)
// List<Process>
-----------------------------
| index | name     | cpu  |
----------------------------
| 0     | shell    | 20%  |
| 1     | code     | 10%  |
...
----------------------------
```

### current state

* a simple repl
* a simple version of `dir`

```bash
# setup with
cargo build
# run with
target/debug/<project-name>
```

### license

LICENSE: MIT
