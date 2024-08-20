//https://solved.ac/profile/javascriptminsun


const input = require("fs")
    .readFileSync(process.stdin.fd)
    .toString()
    .trim()
    .split("\n")
    .map((r) => r.split(" ").map(Number));

const [[N, M, V], ...nodes] = input;

function dfs() {
    let graph = [...Array(N + 1)].map(() => []);
    for (let [u, w] of nodes) {
        graph[u].push(w);
        if (!graph[w].includes(u)) {
            graph[w].push(u);
        }
    }

    graph.forEach((el) => el.sort((a, b) => b - a));
    let visited = [];
    let stack = [V];

    while (stack.length) {
        let currentNode = stack.pop();
        if (!visited.includes(currentNode)) {
            visited.push(currentNode);
        }

        for (let nextNode of graph[currentNode]) {
            if (!visited.includes(nextNode)) {
                stack.push(nextNode);
            }
        }
    }
    return visited;
}
console.log(dfs().join(" "));

//  ------------------------------------

function bfs() {
    let graph = [...Array(N + 1)].map(() => []);
    for (let [u, w] of nodes) {
        graph[u].push(w);
        if (!graph[w].includes(u)) {
            graph[w].push(u);
        }
    }
    graph.forEach((el) => el.sort((a, b) => a - b));

    let visited = [];
    let queue = [V];

    while (queue.length) {
        let currentNode = queue.shift();
        if (!visited.includes(currentNode)) {
            visited.push(currentNode);
        }
        for (let nextNode of graph[currentNode]) {
            if (!visited.includes(nextNode)) {
                queue.push(nextNode);
            }
        }
    }
    return visited;
}
console.log(bfs().join(" "));
