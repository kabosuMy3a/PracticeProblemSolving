const fs = require("fs");
const lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n")
const N = parseInt(lines[0]);
const nums = lines.slice(1).map(s => +s);

let ans = 0 ;

const set = new Set();
set.add(nums[0] + nums[0]);


for(let i = 1 ; i < N ; i++){
    for(let j = 0 ; j < i ; j++){
        const cur = nums[i] - nums[j];
        if(set.has(cur)){
            ans = Math.max(ans, cur + nums[j]);
        }
    }

    for(let j = 0 ; j <= i ; j++){
        set.add(nums[j] + nums[i]);
    }
}

console.log(ans);
