const fs = require("fs");
let lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n")

const [N,_K] = lines[0].split(" ").map((s) => +s);
const nums = lines[1].split(" ").map((s) => BigInt(s));
const K = BigInt(_K);

let left = 0
let right = N -1;
let ans = 0n;

const Max = (a,b) => a > b ? a : b;
const Min = (a,b) => a < b ? a : b;

while(left < right){
    const lv = nums[left] ;
    const rv = nums[right];
    let max = Max(lv,rv);
    let min= Min(lv,rv)

    //K 연산과 1 연산 만으로 gap 을 0 으로 만드는게 목표
    let gap = max - min ;
    // K 연산 최대로 해서 gap 감소
    ans += gap / K;
    gap %= K ;

    ans += Min(
        //1 연산으로 0으로 만드는게 최솟값
        gap,
        //K 연산으로 마이너스로 만든 후에 더해서 0
        -(gap - K) + 1n
    )

    left++;
    right--;
}


console.log(ans.toString());
