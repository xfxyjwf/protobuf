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
Usage: protoc [OPTION] PROTO_FILES
Parse PROTO_FILES and generate output based on the options given:
  -IPATH, --proto_path=PATH   Specify the directory in which to search for
                              imports.  May be specified multiple times;
                              directories will be searched in order.  If not
                              given, the current working directory is used.
  --version                   Show version info and exit.
  -h, --help                  Show this text and exit.
  --encode=MESSAGE_TYPE       Read a text-format message of the given type
                              from standard input and write it in binary
                              to standard output.  The message type must
                              be defined in PROTO_FILES or their imports.
...
$ cat > foo.proto <<EOF
syntax = "proto3";
package test;
message Foo {
  int32 value = 1;
}
EOF
$ protoc —js_out=import_style=commonjs:. foo.proto
$ cat foo_pb.js
/**
 * @fileoverview
 * @enhanceable
 * @suppress {messageConventions} JS Compiler reports an error if a variable or
 *     field starts with 'MSG_' and isn't a translatable message.
 * @public
 */
// GENERATED CODE -- DO NOT EDIT!

var jspb = require('google-protobuf');
var goog = jspb;
var global = Function('return this')();

goog.exportSymbol('proto.test.Foo', null, global);
...
```

## In the browser

Visit https://unpkg.com/google-protocol-compiler/index.html to access the
browser version of this protocol compiler. Type the .proto file content in
the input boxes and click the “Generate” button to see what protoc generates.
It’s useful to do some quick experiments to understand how protoc works.

## As a node.js module

Add a dependency on "google-protocol-compiler" and then you can generate code
on the fly. Example:

```javascript
var generator = require('google-protocol-compiler');

generator.onReady(() => {
  console.log(generator.versionNumber);
  console.log(generator.languageList);

  const name = 'foo.proto';
  const content = `
    syntax = "proto3";
    package test;
    message Foo {
      int32 value = 1;
    }
  `;
  const language = 'Javascript';
  const parameters = 'import_style=commonjs';
  const result = generator.generateCode(name, content, language, parameters);
  if (result.error) {
    console.log('Failed to generate code: ', result.error);
  } else {
    console.log(result.files);
  }
});
```