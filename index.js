const addon = require('./build/Release/addon');
console.log(addon.dec2bin('119'));
const binary = addon.dec2bin('9223372036854775799');
console.log(binary);
console.log(9223372036854775799);