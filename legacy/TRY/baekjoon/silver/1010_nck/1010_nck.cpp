#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);
    int T ; std::cin >> T ;
    for(int t = 0; t < T ; t++){
        long long ans = 1 ;
        int k, n ; std::cin >> k >> n ;
        for(int i = n ; i > n - k ; i--){
             ans *= i ;
             ans /= ((n + 1) - i);
        }
        std::cout << ans <<"\n";
    }
    
    return 0 ;
}