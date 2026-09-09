// Run against the actual JPEXS-decompiled class and timeline scripts.
const {createHarness} = require('./questlist/harness.cjs');
const harness = createHarness(process.argv[2], process.argv[3]);
require('./questlist/item.test.cjs')(harness);
if (process.argv[3]) {
  require('./questlist/layout.test.cjs')(harness);
  require('./questlist/debug.test.cjs')(harness);
}
harness.run();
