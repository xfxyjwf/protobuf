# How does protoc -I flag work

Feng Xiao, 2017/07/12

A .proto file can use an import statement to reference types defined in another .proto file, and for protoc to locate the imported .proto file, a “-I” flag (shorthand for --proto_path) is used to tell protoc where to look for the imported files. This looks very much like the “-I” flag of the C++ compiler, and people tend to use protoc “-I” flag like how they would use the same C++ compiler flag. This, however, usually leads to confusing results because there are fundamental differences between protoc “-I” flag and C++ compiler “-I” flag.

Recent users reports about issues of protoc “-I” flag:

* https://github.com/google/protobuf/issues/3022
* https://github.com/google/protobuf/issues/3044
* https://github.com/google/protobuf/issues/3183
* https://github.com/google/protobuf/issues/3242

In all cases, protoc works as intended but nonetheless its behavior confuses users. There is a command line help text for the “-I” flag but it’s far from enough for users to understand it correctly. This document aims to provide a more detailed explanation of how the protoc “-I” flag works and hope it can make the “-I” flag more understandable.

## Import path

Protobuf has an import statement to import types defined in another .proto file. It’s used in conjunction with the “-I” flag, much like the #include directive in C++. However, unlike a C++ #include directive, the file path used in the protobuf import statement is actually significant and will affect code generation. For example, importing the same file src/foo.proto as ‘import “src/foo.proto”;’ and ‘import “foo.proto”;’ will cause protoc to generate different code. This import path is used by protoc as a unique identifier for a .proto file and it must stay the same in every place the file is imported.

Example of invalid imports:

    // file: lib1/foo.proto
    message Foo {}
    // file: lib1/bar.proto
    import “foo.proto”;
    message Bar { optional Foo value =1 ; }
    // file: lib2/baz.proto
    import “lib1/foo.proto”; 
    message Baz { optional Foo value = 1; }

In the above example, “lib1/foo.proto” is imported under two different import names and one of them is guaranteed to not work. What makes it worse is that it will appear to the protocol compiler as if there are two files, “foo.proto”, and “lib1/foo.proto”, and will lead to confusing compiler error messages when you build the generated code.

So before you invoke protoc to generate code for you .proto files, you need to determine an import path for each of your .proto files and use it consistently in all import statements. For example, the descriptor.proto file bundled with protobuf library must be imported as ‘import “google/protobuf/descriptor.proto”;’. You cannot import it using any other path.

## “-I” flag and file path on the command line

To generate code for a .proto file, you need to list it explicitly on the protoc command line. As of protobuf 3.3.0 release, the file path you use can be either the absolute path, or the relative path from the current working directory. Regardless of which kind of path you use, there must be a matching “-I” flag that is a prefix of the file path and after stripping this prefix from the file path, the resulting path should be the import path of the .proto file.

For example, suppose you have a file /home/xiaofeng/src/foo/bar.proto and /home/xiaofeng is the current working directory.

    ~$ protoc --cpp_out=. src/foo/bar.proto (1)

In the above case, protoc will automatically add “-I.” since no “-I” flag is explicitly specified, and “.” is considered a prefix for all relative file paths. protoc will use “src/foo/bar.proto” as the import path and if the file is imported anywhere, it must be imported as ‘import “src/foo/bar.proto”;’. If not, the code generated above will not work with the code you later generate for other .proto files that import src/foo/bar.proto.

If you instead want to use “foo/bar.proto” as the import path of the file, you must specify “-Isrc” on the command line:

	  ~$ protoc --cpp_out=. -Isrc src/foo/bar.proto (2)

Likewise, if you are using absolute path for the file, you must specify a “-I” flag with an absolute path. For example:

	  ~$ protoc --cpp_out=. -I/home/xiaofeng/src /home/xiaofeng/src/foo/bar.proto (3)

(3) will produce exactly the same output as (2) because in both cases protoc use “foo/bar.proto” as the import path.

If you specify multiple “-I” flags, protoc will match them in the provided order. For example:

	~$ protoc --cpp_out=. -I. -Isrc src/foo/bar.proto (4)

In (4), protoc will match “-I.” with src/foo/bar.proto because it comes before “-Isrc” and as a result protoc will consider “src/foo/bar.proto” as the import path.

## “-I” flag and imported file searching

When a proto file imports other files, protoc will search for those files using their import path in the directories specified in the “-I” flag. For example:

	  ~$ protoc --cpp_out=. -I. -Isrc src/foo/bar.proto (5)

Suppose src/foo/bar.proto has the following content:

    syntax = “proto2”;
    package xiaofeng;
    import “foo/baz.proto”;
    message Bar {}

Protoc will first check whether ~/foo/baz.proto exists for the “-I.” flag. If it doesn’t exist, it will then check whether “~/src/foo/baz.proto” exists. If none exists, protoc will report an error.

## Import path and output files

In some languages, the generated file path is determined by the import path. For example, in C++, for a .proto file with import path foo/bar.proto, protoc will generate foo/bar.pb.h and foo/bar.pb.cc in the output directory.

## Common mistakes

### Use proto imports like C++ includes

Proto imports look like C++ includes but work very differently. Using it like C++ includes is guaranteed to cause problems. Instead, users should carefully choose the import path for their protos and construct the "-I" flags accordingly.

### Specify unused “-I” flags

Many users tend to specify many “-I” flags probably thinking it makes it easier for protoc to find imports. However, as protoc uses “-I” flags to determine the import path of the .proto files, an unnecessary “-I” flag can cause protoc to get the wrong import path and either generate unexpected code or simply refuses to compile at all.

For example, suppose src/foo/bar.proto has an import of ‘import “foo/baz.proto”;’, the following protoc invocation won’t work:

	  ~$ protoc --cpp_out=. -I. -Isrc src/foo/bar.proto src/foo/baz.proto (6)

That’s because protoc determines the import path of “src/foo/baz.proto” is “src/foo/baz.proto” due to the presence of “-I.” and since it’s imported using a different name in src/foo/bar.proto, protoc thinks there are two baz.proto file, one is “src/foo/baz.proto” and the other is “foo/baz.proto”. What makes it worse is that protoc will happily generate code for this but the generated C++ code just doesn’t compile.

