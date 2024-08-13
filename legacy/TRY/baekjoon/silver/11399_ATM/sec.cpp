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
    int prev = 0; ans += pi[0];
    for(int i =1 ; i < N ; i++){
        prev += pi[i-1] ;
	ans += prev + pi[i] ; 
	
    }
    
    std::cout << ans << "\n";
    return 0 ;
}
