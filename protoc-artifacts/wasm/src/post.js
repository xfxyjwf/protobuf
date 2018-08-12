var systemHelper = addFunction(function (p1, p2, p3) {
  // console.log(p1, p2, p3);
  if (p1 == 1) {
    const name = UTF8ToString(p2);
    return require('fs').existsSync(name);
  } else if (p1 == 2) {
    const name = UTF8ToString(p2);
    try {
      const content = require('fs').readFileSync(name, 'utf8');
      const ret = allocate(intArrayFromString(content), 'i8', ALLOC_NORMAL);
      return ret;
    } catch (err) {
      console.log('Failed to open file: ', name, ", error: ", err);
      return 0;
    }
  } else if (p1 == 3) {
    const name = UTF8ToString(p2);
    try {
      if (!require('fs').existsSync(name)) {
        require('fs').mkdirSync(name);
      }
      return true;
    } catch (err) {
      console.log('Failed to create directory: ', name, ", error: ", err);
      return false;
    }
  } else if (p1 == 4) {
    const name = UTF8ToString(p2);
    const content = UTF8ToString(p3);
    try {
      require('fs').writeFileSync(name, content);
      return true;
    } catch (err) {
      console.log('Failed to write file: ', name, ", error: ", err);
      return false;
    }
  } else {
    console.log('unknown op: ' + p1);
    return -1;
  }
}, 'iii');

Module["onRuntimeInitialized"] = function () {
  if (typeof Module["_SetSystemHelper"] !== "undefined") {
    Module._SetSystemHelper(systemHelper);
  }
};
Module["GetGeneratorFunction"] = function () {
  const rawFunction = Module.cwrap('Generate', 'number', ['string']);
  return function (input) {
    const raw = rawFunction(JSON.stringify(input));
    const result = Module.UTF8ToString(raw);
    Module._free(raw);
    return JSON.parse(result);
  };
};
Module["GetListLanguagesFunction"] = function () {
  const rawFunction = Module.cwrap('ListLanguages', 'number', []);
  return function () {
    const raw = rawFunction();
    const result = Module.UTF8ToString(raw);
    Module._free(raw);
    return JSON.parse(result);
  };
};
Module["GetVersionNumberFunction"] = function () {
  const rawFunction = Module.cwrap('GetVersionNumber', 'number', []);
  return function () {
    const raw = rawFunction();
    const result = Module.UTF8ToString(raw);
    Module._free(raw);
    return result;
  };
};
