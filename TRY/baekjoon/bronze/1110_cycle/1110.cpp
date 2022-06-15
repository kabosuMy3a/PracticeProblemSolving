#include <iostream>

int main(){
    int N ; std::cin >> N ; int ans = 1; int n = N ;
    while(1){
        int a = n / 10 ;
        int b = n % 10 ;
        int c = a+b ;
        n = (b * 10) + (c % 10); 
        if(n == N){
            std::cout << ans << "\n";
            break; 
        }
        ans++ ;
    }
    
    return 0 ;
}