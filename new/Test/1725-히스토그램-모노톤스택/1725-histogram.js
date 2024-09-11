const fs = require("fs");
const lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n");

for(const line of lines.slice(0,-1) ){
    const nums =  line.split(" ").slice(1).map((each) => +each);

    const stack = [{height: nums[0], count: 1}];
    let ans = 0 ;

    for(const num of nums.slice(1)){
        const height = num ;
        let prevCounts = 0;

        while(true){
            if(stack.length === 0){
                break;
            }
            const {height: topHeight, count: topCount} = stack[stack.length -1];
            if(topHeight === height){
                stack.pop();
                stack.push({height, count: topCount + prevCounts + 1});
                break;
            } else if(topHeight < height){
                stack.push({height, count: prevCounts + 1});
                break;
            } else {
                stack.pop();
                ans = Math.max(ans, topHeight * (topCount + prevCounts));
                prevCounts += topCount
            }
        }
        if(stack.length === 0){
            stack.push({height, count: prevCounts + 1})
        }
    }

    let prevCounts = 0 ;
    while(stack.length > 0) {
        const {height: topHeight, count: topCount} = stack[stack.length -1];
        ans = Math.max(ans, topHeight * (topCount + prevCounts));
        prevCounts += topCount
        stack.pop();
    }

    console.log(ans);

}
