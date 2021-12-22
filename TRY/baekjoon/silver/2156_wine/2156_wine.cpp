#include <iostream>
#include <algorithm>
#include <vector>

// 스스로 풀지 못했다.
// 풀이 답을 보고서도 완벽히 이해는 되지 않는다.
// 그래도 점화식 세우는 법을 알아서 좋은 경험이 된 것 같다.
// 고로, 다양한 DP를 꾸준히 풀어서 스스로 풀어보는 경험을 갖자.

int wine[10001] = {0} ;
int max_until[10001] = {0}  ;

int main(){
    int n ; 
    std::cin >> n ; 
    for(int i = 1 ; i <= n ; i++){
        int a ; 
        std::cin >> a; 
        wine[i] =  a; 
    }

    max_until[0] = wine[0] ;
    max_until[1] = wine[1] ;
    max_until[2] = wine[2] + wine[1] ;

    for(int i = 3 ; i<= n ; i++){
        std::vector<int> dp_case ;
        
        // ?X
        // ?XO
        // ?XOO
        // ?에서의 정확한 상태는 모르지만 ?까지 최대로 마시는 경우는 알고 있다

        //지금 안 먹는 경우
        dp_case.push_back(max_until[i-1]);
        //직전에 안 먹는 경우
        dp_case.push_back(wine[i] + max_until[i-2]);    
        //전 전에 안먹는 경우
        dp_case.push_back(wine[i] + wine[i-1] + max_until[i-3]);
        
        max_until[i] = * std::max_element(dp_case.begin(), dp_case.end());

    }

    std::cout << max_until[n] << std::endl ;

}
