const fs = require("fs");
const lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n");

class Node {
    constructor() {
        this.next = {};
        this.value = "";
    }
}

class Trie {
    constructor() {
        this.root = new Node();
    }

    insert(words) {
        let node = this.root ;
        for(const word of words ){
            if(!node.next[word]){
                node.next[word] = new Node();
                node.next[word].value = word;
            }
            node = node.next[word];
        }
    }


    solve(node, level = 0) {
        if(!node){
            node = this.root;
        } else {
            console.log("--".repeat(level-1) + node.value)
        }
        const nextKeys = Object.keys(node.next).sort();
        for(const nextKey of nextKeys){
            this.solve(node.next[nextKey], level + 1);
        }
    }
}


const ants = lines.slice(1);
const trie = new Trie();

for (const ant of ants){
    const rooms = ant.split(" ").slice(1);
    trie.insert(rooms);
}
trie.solve(undefined);

