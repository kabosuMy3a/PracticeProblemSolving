#include <iostream>
#include <cmath>

int main(){
    int N ; std::cin >> N ; int ans = 0 ;
    for(int i = 1 ; i < sqrt(N) ; i++) if(N % i == 0) ans += 2 ;
    if(sqrt(N) == (int)sqrt(N)) ans+= 1 ;
    return 0 ;
}