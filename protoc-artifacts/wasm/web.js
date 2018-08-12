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

class GeneratorResult {
  constructor(result) {
    this.error = result.error;
    this.files = result.files;
  }

  /**
   * @returns {?string} An error message if code generation fails.
   */
  get error() {
    return this.error;
  }

  /**
   * @returns {Object.<string,string>} List of generated files.
   */
  get files() {
    return this.files;
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
   * @returns {string[]} A list of supported languages.
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

/**
 * @typedef {Object} LanguageList
 * @property {string[]} languages
 */
class LanguageList {
  /**
   * @param {string[]} languages 
   */
  constructor(languages) {
    this.languages = languages;
  }
}
