const fs = require("fs");
const lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n");

const targets = lines.slice(1).map((s) => +s).sort((a,b) => a-b)

let defile_angle = 1 ;
let ans = 0 ;
targets.forEach((target) => {
    if(defile_angle - 1 === target) {
        //직전 모독각이랑 같은 숫자인 경우
    } else {
        ans += target - defile_angle;
        defile_angle++;
    }
})
console.log(ans);
