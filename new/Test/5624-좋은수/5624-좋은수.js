const fs = require("fs");
const lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n")
const N = parseInt(lines[0]);
const nums = lines.slice(1).map((line => line.split(" ").map(s => +s)))[0];

let ans = 0 ;

const arr = new Array(2000001);

arr[nums[0] + nums[0]] = 1 ;

for(let i = 1 ; i < N ; i++){
    for(let j = 0 ; j < i ; j++){
        const cur = nums[i] - nums[j];
        if(arr[cur] !== undefined){
            ans +=1;
            break;
        }
    }

    for(let j = 0 ; j <= i ; j++){
        arr[nums[j] + nums[i]] = 1
    }
}

console.log(ans);
