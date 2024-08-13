#include <iostream>
#include <algorithm>

int e[10000];
int N ;

int main(){
    std::cin >> N ; N *= 2 ;
    for(int i = 0 ; i < N ; i++){
        std::cin >> e[i];
    }
    std::sort(e, e+N);
     
    int min_e = 200001;
    for(int i = 0 ; i < N/2 ; i++){
        int cur = e[i] + e[N-1-i];
        std::cout << cur << "\n";
        if(min_e > cur) min_e = cur ;
    }
 
    std::cout << min_e << std::endl;
    
    return 0 ;
}