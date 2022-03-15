#include <iostream>

int a[1'000'000];
int main(){
    int N ; std::cin >> N ; int ans = 0 ;
    for(int i = 0 ; i < N ; i++){
        std::cin >> a[i]; 
    }
    int b, c; std::cin >> b >> c ;
    for(int i = 0 ; i < N ; i++){
        a[i] -= b ; ans++ ;
        if(a[i] > 0){
            if(a[i] % c != 0) ans += 1 ;
            ans += a[i] / c ;
        }
    }
    
    std::cout << ans << "\n";
    return 0 ;
    
}
