#include <iostream> 

int main(){
    std::ios_base::sync_with_stdio(0x0);
    std::cin.tie(0x0);
    int T ; std::cin >> T;
    for(int t = 0 ; t < T ; t++){
        int N, M, K, D ;
        std::cin >> N >> M >> K >> D ;
        int X = (N * M) * (K * (M - 1) + (N-1) * M) / 2 ;
        int B = D / X ;

        if(B >= 1) std::cout << X * B << "\n";
        else std::cout << -1 << "\n";
    }   
    
    return 0 ;
}
