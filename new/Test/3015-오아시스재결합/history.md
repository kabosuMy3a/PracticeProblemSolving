오아시스 재결합 소식을 들은 상태에서 문제를 발견했기 때문에 그냥 넘어갈 수 없었다...  
[오아시스 재결합](https://www.acmicpc.net/problem/3015) 문제는 풀이없이 접근했을 때, 까다로운 문제였다.

# Abstract 

정해가 아닌 풀이는 아이디어가 떠올라 5시간 정도 디벨롭 했는데 구현에 실패했다.  
먼저 정해부터 살펴보자.

----

# 정해

```javascript
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
```

[기본적으로 이해하기 좋았던 글](https://justicehui.github.io/coi/2018/11/06/BOJ3015/)


전제 
1. 스택은 앞에서 부터 순서대로 넣는다
2. 스택 내부는 감소 상태를 유지한다.

왜?   
스택을 다음 사람이 볼 가능성이 있는 사람들로 유지하기 위해서.


1. 나보다 키가 작은 사람들은, 나 때문에 다음 사람들이 보지 못한다.   
=> 빼버린다.


2. 나보다 키가 큰 애들은, 나와 상관 없이 볼 수 있다.  
=> 유지하고, 나도 넣는다.


3. 나와 키가 같은 사람들은, 나를 볼 수 있는 사람이면 모두 볼 수 있다.  
=> 몇 명인지 계산하기 위해 전부 빼버리고, 나를 넣을 때 빼버린 나와 키가 같은 사람들을 전부 넣는다.   
전부 다음 사람이 볼 수 있는 사람들이기 때문에

   
정답은 언제 증가하는가?  
(1) 다른 사람을 뺄 때   
(2) 나를 넣을 때 스택 안에 나보다 키가 큰 애가 있다면  


여기서 3번을 최적화한 것이 정해임을 이해할 수 있다.  
또한 3번을 정해로 최적화하면 스택이 감소 상태가 아닌 순감소 상태가 되므로,  
(2)번 조건을 스택 안에 누군가 있다면으로 수정할 수 있다.



<br>

----

정해가 아니고 구현하지 못함
---

내 아이디어는 등산으로 표현하는 것이었다. 실제 등산에서 보이는 것과 조금 다르지만 이미지화 하기 좋았다.   

1. 오르막길에서는 자기 바로 앞이 모든 시야를 가린다.
2. 내리막길에서는 자기 바로 앞이 가리지 않으므로, 자신 가장 앞에 있는 산이 보이고, 가장 앞에 있는 산에 가려지지 않는 부분이 보인다.
3. 평지는 케이스 분류가 필요하다.
   1. 오르막길의 일부인 평지인 경우, 자기 앞의 같은 높이들과 처음으로 높아지는 곳이 보인다.
   2. 내리막길의 일부인 평지인 경우, 자기 앞의 같은 높이들만 보인다. 낮아지는 곳은 보이지 않는다.
   3. 평지만 있는 경우, 오르막길의 일부인 평지와 같다.

구현 흐름은 아래와 같았다.

```typescript
 interface Slope {
  startIdx: number; //오르막길 시작점
  endIdx: number; //오르막길 끝점
  peak: number; //가장 높은 값
}  

type Major = Slope[];
type Minor = Slope[];

```

Major 는 어디서도 볼 수 있는 산의 일부분이다.
Minor 는 바로 앞에 있는 산이면서, Major 가 아닌 부분이다.
```
                        
    4                4  4 
        3       
2                 2          
            1               1
-------------------------------
0  1    2   3     4  5  6   7  
          
major는 [0,1] [5,6] 이 된다.
minor는 [3,4] 가 된다.        

```

이렇게 집합을 모델링 하면 다음 수와의 크기 비교에 따라 3개의 경우로 나눠서 풀 수 있다.


1. 다음 수가 자기보다 작은 경우 (내리막 길)
```javascript
ans += 
    heights[i+1] + 
    minor[0].endIdx - minor[0].startIdx + 1 +
    major.map((each) => each.endIdx - each.startIdx +1) //누적합으로 관리하면 O(N) 으로 계산된다.
```
```
구현 유의사항
i+1 === major[0].endIdx 인 경우 꼭대기이므로, major.shift() 후 계산해야 함.
i+1 === minor[0].endIdx 인 경우 꼭대기이므로, minor.shift() 후 계산해야 함.

i+1 === minor[0].startIdx 인 경우 중복제거 -1
i+1 === major[0].startIdx 인 경우 중복제거 -1
```



2. 다음 수가 자기보다 큰 경우 (오르막 길)
```
ans += heights[i+1]
```

3. 다음 수가 자기와 같은 경우 (평지)

```
높은 수에 가리지 않는 평지와 높은 수에 가리지 않는 평지가 있다.


높은 수에 가리지 않는 평지의 경우 
     ! !     ! !     ! ! 
val: 4 4 4 1 4 4 4 1 4 4 4
----------------------------
idx: 0 1 2 3 4 5 6 7 8 9 A

다음 수가 자기보다 같은 인덱스는 0,1,4,5,8,9 이고 
n 부터 1 까지 합을 구하면 된다. 
n(n+1)/2


높은 수에 가리는 평지의 경우
     ! !     ! !     ! ! 
val: 4 4 4 1 4 4 4 1 4 4 4 5 4
---------------------------------
idx: 0 1 2 3 4 5 6 7 8 9 A B C

다음 수가 자기보다 같은 인덱스는 0,1,4,5,8,9 이고 
n+1 부터 2 까지 합을 구하면 된다. (N + M) * (M - N + 1) / 2.
n(n+3)/2 


구현하기 까다롭지만 O(N)으로 풀 수 있다.
```


구현 당시 4 4 4 1 4 4 4 1 4 4 4 케이스를 발견하니 다 때려치고 정해를 찾아보고 싶어졌다.  
케이스를 나눠서 더럽게 생각했지만, 웰노운 모노톤 스택은 한 번에 해결하더라...

------------------------------




# 후기


알고리즘 분류 스택만 보고 스스로 정해까지 도달하기는 어려워 보이긴 한다.  
생각할수록 케이스 분류 구현문제로 생각하게끔 흘러갔다. 위에처럼 생각해보는 것도 좋은거긴 할까?
잘 모르겠지만 일에서 대부분의 해결해야 온 문제는 구현이니까..
