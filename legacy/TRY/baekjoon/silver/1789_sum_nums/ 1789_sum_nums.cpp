#include <iostream>

int main(){
    
    long long a ; std::cin >> a; 
    long long i = 1 ; long long ans = 0 ;
    while(1){
        a -= i ; i++ ; ans++ ;
        if(a < i){
            std::cout << ans ;
            return 0 ;
        }
    }
    
    
    return 0 ;
}