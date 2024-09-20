const fs = require("fs");
const [l,r] = fs.readFileSync(process.stdin.fd).toString().trim().split(" ").map((s) => +s);

/*
*
0 ~9  s[1]
s[0] * 10 + 45 * 1

0 ~ 99 s[2]
s[1] * 10 + 45 * 10

0 ~ 999 s[3]
s[2] * 10 + 45 * 100

0 ~ 9999 s[4]
s[3] * 10 + 45* 1000
*
**/

//0, 0~9, 0 ~ 99, 0 ~ 999 , ...
const s = [0];
for(let i = 1 ; i <= 9 ; i++){
    s[i] = s[i-1] * 10 + 45 * (10**(i-1))
}

//0, 1, 3, 6, 10 ,15, ... 36, 45
const firstDigitSumArray = [0];
for(let i = 1 ; i <= 9 ; i++){
    firstDigitSumArray[i] = firstDigitSumArray[i-1] + i
}


/*
0 ~ 3999
4000 ~ 4899
4900 ~ 4939
4940 ~ 4943
*/

const f = (n, preSum) => {
    if(n <= 0 ){
        return 0 ;
    }

    let rst = 0 ;
    let i = 9 ;

    while(true){
        if(i < 0 ){
            break;
        }
        if(Math.floor(n / (10**i))){
            break;
        }
        i--;
    }

    const digit = Math.floor(n / (10**i));

    // 0~999 구간 계산하기
    rst += s[i] * digit;
    //앞 자리 더해주기
    if(i > 0 ){
        rst += firstDigitSumArray[digit-1] * (10**i) ;
        rst += digit * (10 ** i) * preSum;
    } else {
        rst += firstDigitSumArray[digit];
        rst += (digit+1) * (10 ** i) * preSum;
    }

    const rem = n % (10 ** i);
    if(rem === 0 && i > 0){
        rst += digit + preSum ;
    }
    rst += f(rem, preSum + digit);

    return rst ;
}

//4943
console.log(f(r, 0) - f(l-1, 0));

