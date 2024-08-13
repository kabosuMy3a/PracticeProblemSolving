/////////////////////////////////////////////////////////
// https://blog.psst54.me/cse/js-coding-test-1-input ////
/////////////////////////////////////////////////////////

const fs = require("fs");
const input = fs.readFileSync(process.stdin.fd, "utf-8");
const lines = input.split("\n");
//lines = ["5", "1 1", "2 3", "3 4", "9 8", "5 2"];


const T = parseInt(lines[0]);
const arr = lines.slice(1, T+1);
const pairList = arr.map((line => line.split(" ").map(s => parseInt(s))));

for(const pair of pairList){
  const [a,b] = pair;
  console.log(a+b);
}

