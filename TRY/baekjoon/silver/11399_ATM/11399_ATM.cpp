#include <iostream>
#include <algorithm>

int N ;
int pi[1000];
int ans = 0 ;
int main(){
    
    std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        std::cin >> pi[i];
    }
    std::sort(pi, pi+N);
    for(int i = 0 ; i < N ; i++){
        ans += (N-i) * pi[i]; 
    }
    
    std::cout << ans << "\n";
    return 0 ;
}