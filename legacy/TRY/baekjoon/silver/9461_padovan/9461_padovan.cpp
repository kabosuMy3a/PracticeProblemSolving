#include <iostream>

long long ans[101];
int T, N ;

int main(){
    std::cin >> T ;
    
    ans[1] = 1 ; ans[2] = 1 ; ans[3] = 1;
    ans[4] = 2 ; ans[5] = 2 ;
    
    for(int i = 6 ; i <= 100 ; i++){
        ans[i] = ans[i-5] + ans[i-1];
    }
    
    for(int t = 0 ; t < T ; t++){
        std::cin >> N ;
        std::cout << ans[N] << "\n";
    }
    
    return 0;
}