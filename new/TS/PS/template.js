/////////////////////////////////////////////////////////
// https://blog.psst54.me/cse/js-coding-test-1-input ////
/////////////////////////////////////////////////////////

const fs = require("fs");
const lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n");

//const T = parseInt(lines[0]);
const arr = lines.slice(1).map((line => line.split(" ").map(s => +s)));
arr.forEach(([a,b]) => console.log(a+b));
