#include <iostream>
#include <cmath>

int main(){
    while(1){
        long double m, a, b ; 
        std::cin >> m >> a >> b;
        if(m == 0 && a == 0 && b == 0) return 0;
        a /= 3600 ; b /= 3600 ;
        int t = (int)round(m/a -  m/b) ;
        int h = t/3600 ; t %= 3600 ;
        int mm = t/60 ; t %= 60 ;
        int ss = t ;
        std::cout << h << ":" ;
        if(mm < 10) std::cout << "0" ;
        std::cout << mm << ":" ;
        if(ss < 10) std::cout << "0" ;
        std::cout << ss << "\n";
    }
    return 0 ;
}