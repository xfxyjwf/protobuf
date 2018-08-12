var generator = require('./util.js');

generator.onReady(() => {
    console.log('Version number: ', generator.versionNumber);
    const languages = generator.languageList;
    for (var language in languages) {
        const result = generator.generateCode('foo/bar.proto', 'syntax = "proto3"; package xiaofeng; import "google/protobuf/descriptor.proto"; option java_multiple_files = true; message Foo { int32 value = 1; }', language, '');
        console.log(language, Object.getOwnPropertyNames(result.files));
    }
});
