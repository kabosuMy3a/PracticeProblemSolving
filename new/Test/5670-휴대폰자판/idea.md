## Abstract
찾아본 트라이 예제들은 주로 insert, search 의 기능이 있다.  
[휴대폰 자판](https://www.acmicpc.net/problem/5670) 문제는 search 대신, 트라이를 전체 탐색하면서 풀 수 있다.

## 아이디어
1. 앞글자가 동일하면 일치하는 부분까지 자판을 누른 횟수는 동일하다.
2. 자판을 눌러야 하는 때마다 cnt 를 늘려주면 된다.
   1. 글자가 한 개일 때를 포함하여 첫 글자는 스스로 누른다. (출발선)
   2. 다음 글자가 2개 이상인 경우 (갈림길)
   3. 다음 글자가 1개지만, 안 누를 수도 있는 경우 (경유지)

```
예시 

hell  
hello  
help
heaven


hel 까지 입력한 경우 l,p 갈림길이 있다. (2-ii)
hell 까지 입력한 경우 hell 에서 끝낼 수도, 하나를 더 눌러서 hello 일 수도 있다.(2-iii)
반면 heaven 은 he 입력 후 a 를 누르면 더 이상 선택지가 없다.
```



## 상세 구현
1. parameter 에 지금까지 자판을 누른 횟수를 전달한다. (아이디어 1)
2. 2번 아이디어에 맞춰 구현

```javascript

  solve(node, pressed){
        if(!node){
            node = this.root;
            //출발선
            pressed += 1;
        }

        //현재 노드의 누른 횟수는 호출 전에 미리 계산했음
        if(node.isEnd){
            this.totalCnt += pressed;
        }

        const nextKeys = Object.keys(node.next);
        //출발선이 갈림길인 경우 예외처리, 갈림길, 경유지
        if(node !== this.root && nextKeys.length > 1 || (nextKeys.length === 1 && node.isEnd)){
            pressed += 1;
        }

        for(const nextKey of nextKeys){
            this.solve(node.next[nextKey], pressed);
        }
    }


```


## 전체 코드 

```javascript

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

        if(node.isEnd){
            this.totalCnt += pressed;
        }

        const nextKeys = Object.keys(node.next);
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

```
