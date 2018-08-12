var Module = typeof Module !== 'undefined' ? Module : require('./build/util-wasm.js');

const listLanguagesFunction = Module.GetListLanguagesFunction();
const generateCodeFunction = Module.GetGeneratorFunction();
const getVersionNumberFunction = Module.GetVersionNumberFunction();

let isReady = false;
let readyCallbacks = [];

const chainCallback = Module.onRuntimeInitialized;
Module.onRuntimeInitialized = function () {
  if (chainCallback) {
    chainCallback();
  }
  isReady = true;
  readyCallbacks.forEach(callback => {
    callback();
  });
}

class LanguageDescription {
  constructor(description) {
    /**
     * @type {string}
     * @description Command line flag to generate code for this language; e.g.: "--cpp_out"
     */
    this.protocOutputFlag = description.protocOutputFlag;
    /**
     * @type {?string}
     * @description If supported, command line flag to pass options for this language; e.g.: "--cpp_opt"
     */
    this.protocOptionFlag = description.protocOptionFlag;
  }
}

class GeneratorResult {
  constructor(result) {
    /**
     * @type {?string}
     * @description An error message if code generation fails.
     */
    this.error = result.error;
    /**
     * @type {Object.<string, string>}
     * @description List of generated files.
     */
    this.files = result.files;
  }
}

/**
 * @callback GeneratorReadyCallback
 */

class CodeGenerator {
  constructor() {
  }

  get isReady() {
    return isReady;
  }

  /**
   * 
   * @param {GeneratorReadyCallback} callback 
   */
  onReady(callback) {
    if (isReady) {
      callback();
    } else {
      readyCallbacks.push(callback);
    }
  }

  /**
   * @returns {string} Version number of the protocol compiler; e.g., "3.6.1".
   */
  get versionNumber() {
    if (!isReady) {
      throw "generator is not ready yet.";
    }
    return getVersionNumberFunction();
  }

  /**
   * @returns {Object.<string, LanguageDescription>} A list of supported languages.
   */
  get languageList() {
    if (!isReady) {
      throw "generator is not ready yet.";
    }
    return listLanguagesFunction().languages;
  }

  /**
   * @param {string} name .proto file name; e.g., foo/bar.proto
   * @param {string} content content of the .proto file
   * @param {string} language the language to generate; must be in {@link CodeGenerator#languageList}.
   * @param {string} parameters additional code generation parameters; e.g. import_style=commonjs
   * @returns {GeneratorResult}
   */
  generateCode(name, content, language, parameters) {
    if (!isReady) {
      throw "generator is not ready yet.";
    }
    return generateCodeFunction({ name: name, content: content, language: language, parameters: parameters });
  }
}

if (typeof module !== 'undefined') {
  module.exports = new CodeGenerator();
}