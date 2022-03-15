#include <iostream>

int main(){
    
    int N ; std::cin >> N ;
    int F ; std::cin >> F ;
    N -= (N % 100) ;
    for(int i = N ; i < N + 100 ; i++){
        if((i%F) == 0){
            if(i % 100 < 10) std::cout << 0 ;
            std::cout << i % 100 << "\n";
            break;
        }
    }
    
    return 0 ;
}