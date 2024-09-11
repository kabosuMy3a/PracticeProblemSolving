const fs = require("fs");
let lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n")

const [,M] = lines[0].split(" ").map((s) => +s);
const jaewon= lines[1].split(" ").map((s) => +s);
const people =
    lines.slice(2).map((each)=> each.split(" ").map((s) => +s))
        .map((each, idx) => {
            return {
                sum: each[0] + each[1] + each[2],
                key: idx + 1
            }
        }).sort((a,b) => b.key - a.key)

const ans = [0];
people.forEach((person) => {
    if(ans.length === M){
        return ;
    }
    if(jaewon[0] + jaewon[1] + jaewon[2] >= person.sum){
        ans.push(person.key);
    }
})

console.log(ans.join(" "));
