var diskSourceTreeHelper = addFunction(function(p1,p2) {
  console.log(p1, p2);
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
      console.log('Failed to open file: ', name);
      return 0;
    }
  } else {
    console.log('unknown op: ' + p1);
    return -1;
  }
}, 'iii');

Module["onRuntimeInitialized"] = function() {
  Module._SetDiskSourceTreeHelper(diskSourceTreeHelper);
};
