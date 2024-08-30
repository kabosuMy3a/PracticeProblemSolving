const fs = require("fs");
const lines = fs.readFileSync(process.stdin.fd).toString().trim().split("\n");

class Node {
    constructor() {
        this.next = {};
        this.isEnd = false ;
        this.value = "";
    }
}

class Trie {
    constructor() {
        this.root = new Node();
        this.totalCnt = 0 ;
    }

    insert(word) {
        let node = this.root ;

        for(let char of word){
            if(!node.next[char]){
                node.next[char] = new Node();
                node.next[char].value = char;
            }
            node = node.next[char];
        }

        return node.isEnd = true ;
    }

    solve(node, pressed) {
        if(!node){
            node = this.root;
            pressed += 1;
        }

        //현재 노드의 누른 횟수는 호출 전에 미리 계산했음
        if(node.isEnd){
            this.totalCnt += pressed;
        }

        const nextKeys = Object.keys(node.next);
        //루트가 아니고, 갈림길이 있거나, 외길이지만 경유지인 경우
        if(node !== this.root && nextKeys.length > 1 || (nextKeys.length === 1 && node.isEnd)){
            pressed += 1;
        }

        for(const nextKey of nextKeys){
            this.solve(node.next[nextKey], pressed);
        }
    }
}


let t = 0 ;
while (t < lines.length){
    const n = parseInt(lines[t]);
    const arr = lines.slice(t + 1, t + 1 + n)

    const trie = new Trie();

    for(a of arr){
        trie.insert(a);
    }

    trie.solve(undefined, 0);
    console.log((trie.totalCnt/n).toFixed(2));
    t += n + 1;
}

