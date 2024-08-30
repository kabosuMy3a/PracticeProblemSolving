const fs = require("fs");
const heights = fs.readFileSync(process.stdin.fd).toString().trim().split("\n").slice(1).map(s=> +s);


const stack = [];
let ans = 0 ;

for(let i = 0; i < heights.length ; i++){
    const height = heights[i];
    let sameHeightCount = 1 ;

    while(true){
        if(stack.length === 0){
            break;
        }

        const {height: prevHeight, sameHeightCount: prevSameHeightCount} = stack[stack.length -1];
        if(prevHeight > height){
            break;
        }
        stack.pop();
        ans += prevSameHeightCount ;
        if(prevHeight === height){
            sameHeightCount = prevSameHeightCount + 1;
        } else {
            sameHeightCount = 1;
        }

    }

    if(stack.length !== 0){
        ans++;
    }
    stack.push({height, sameHeightCount});
}

console.log(ans);
