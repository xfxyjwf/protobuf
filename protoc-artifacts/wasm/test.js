var m = require('./util.js');

m.generator.onReady(() => {
    console.log('Version number: ', m.generator.versionNumber);
    const languages = m.generator.languageList;
    languages.forEach(language => {
        const r = m.generator.generateCode('foo/bar.proto', 'syntax = "proto3"; package xiaofeng; option java_multiple_files = true; message Foo { int32 value = 1; }', language, '');
        console.log(language, Object.getOwnPropertyNames(r.files));
    });
});