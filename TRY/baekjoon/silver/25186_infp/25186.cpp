#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);
    
    int N ; std::cin >> N;
    
    long long most = 0 ; long long sum = 0;
    for(int i = 0 ; i < N ; i++){
        int a ; std::cin >> a; sum += a ;
        if(most < a) most = a ;
    }
    sum -= most ;
    
    if(N == 1){
        if(most == 1){
            std::cout << "Happy";
            return 0 ;
        } else {
            std::cout << "Unhappy" ;
            return 0; 
        }
    }
    
    if(most <=  sum){
        std::cout << "Happy" ; 
    } else {
        std::cout << "Unhappy" ;
    }
    
    return 0 ;
}