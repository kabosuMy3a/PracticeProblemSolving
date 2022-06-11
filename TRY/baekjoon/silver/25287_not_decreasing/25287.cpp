#include <iostream>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(0x0) ; std::cin.tie(0x0) ;
    int T ; std::cin >> T ;
    for(int t = 0 ; t < T ; t++){
        int N ; std::cin >> N ;
        
        int prev = 0 ; int is_impossible = 0 ;
        for(int i = 0 ; i < N ; i++){
            int base = N + 1 ;
            int a ; std::cin >> a ;
            int b = base - a ;
            int small = std::min(a,b);
            int big = std::max(a,b);
            if(prev <= small){
                prev = small ; 
            } else if(prev <= big){
                prev = big  ;
            } else {
                is_impossible = 1 ;
            }
        }
        
        if(is_impossible){
            std::cout << "NO\n" ;
        } else {
            std::cout << "YES\n";
        }        
    }
    return 0;
}