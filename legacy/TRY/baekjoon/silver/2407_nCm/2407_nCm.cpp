#include <iostream>


long long ans = 1;
int main(){
    long long n, m ; std::cin >> n >> m ;
    if(n == m){
        std::cout << 1 << "\n";
        return 0;
    }
   
    if(m > (n/2)) m = n - m ;
    for(int i = 0 ; i < m ; i++){
        ans *= (n - i) ;
        ans /= (i+1);
    }
    
    std::cout << ans <<"\n";
    return 0;
}