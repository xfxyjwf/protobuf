const m = require('./build/util-wasm.js');

exports.listLanguages = m.GetListLanguagesFunction();
exports.generateCode = m.GetGeneratorFunction();
