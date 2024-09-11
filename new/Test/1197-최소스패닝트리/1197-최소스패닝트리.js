const fs = require("fs");
const lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n");

const [V, E] = lines[0].split(" ").map(s => +s);
let parents = new Array(V+1);
parents = parents.fill(0).map((v,i) => i)

function find(a){
    if(parents[a] === a){
        return a;
    }
    return parents[a] = find(parents[a]);
}

function union(a,b){
    let parentA = find(a);
    let parentB = find(b);

    if(parentA < parentB){
        parents[parentB] = parentA;
    } else {
        parents[parentA] = parentB;
    }
}

let ans = 0;
const edges = lines.slice(1).map((line) => line.split(" ").map((s) => +s))
    .sort((a,b) => a[2] - b[2]);

for(let [a,b,c] of edges){
    if(find(a) !== find(b)){
        union(a,b)
        ans+= c;
    }
}

console.log(ans);
