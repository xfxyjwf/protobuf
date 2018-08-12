# Google Protocol Compiler

This is an *experimental* web assembly version of Google Protocol Compiler
compiled from protobuf C++ source code. It can be used to generate code for
.proto files just like the native protoc binary but works with node.js and
can even work in the browser.

## As a command line tool

Install the package using npm and the protoc command line tool will be ready
to use:

```bash
$ npm install -g google-protocol-compiler
$ protoc —help
...
$ cat > foo.proto <EOF
...
EOF
$ protoc —js_out=import_style=commonjs:. foo.proto
$ cat foo_pb.js
...
```

## In the browser

Visit ... to access the browser version of this protocol compiler. Type the
.proto file content in the input boxes and click the “Generate” button to see
what protoc generates. It’s useful to do some quick experiments to understand
how protoc works.
