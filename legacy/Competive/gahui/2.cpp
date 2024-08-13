#include <iostream>
#include <algorithm>

int N, a, b;
int main(){
    std::ios_base::sync_with_stdio(0x0);
    std::cin >> N >> a >> b ;
    
    if(N < a + b - 1){
        std::cout << -1 << "\n";
        return 0;
    }

    if(a == 1 && b == 1 && N > 1){
        for(int i = 0 ; i < N  ; i++){
            std::cout << 1 << " ";
        }
        std::cout << "\n";
        return 0 ;
    }
    
    int p = N - (a + b - 1) ; int top = std::max(a,b) ;
    for(int i = 1 ; i < a ; i++){
        std::cout << i << " ";
        if(i == 1){
            for(int i = 0 ; i < p ; i++){
                std::cout << 1 << " ";
            }
        }
    }
    std::cout << top << " ";
    for(int i = b -1 ; i >= 1 ; i--){
        if(a == 1 && i == b-1){
            for(int i = 0 ; i < p ; i ++){
                std::cout << 1 << " ";
            }
        }
        std::cout << i << " ";
 
    }
    std::cout << "\n" ;
   
    return 0 ;
}