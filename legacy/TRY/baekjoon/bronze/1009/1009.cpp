#include <iostream>

int main(){
    int T ; std::cin >> T ; int ans ;
    for(int t = 0 ; t < T ; t++){
        int a ; int b; std::cin >> a >> b;
        ans = a % 10 ;
        for(int i = 1 ; i < b ; i++){
           ans = (ans * a) % 10 ;
        }
        std::cout << ans << "\n";
    }
    return 0;
}