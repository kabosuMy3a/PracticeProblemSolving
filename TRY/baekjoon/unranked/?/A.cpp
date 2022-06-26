#include <iostream>

int main(){
    long long total; std::cin >> total;
    int N ; std::cin >> N ; long long sum = 0 ;
    for(int i = 0 ; i < N ; i++){
        long long a,b; std::cin >> a >> b ;
        sum += (a * b);
    }
    
    if(sum == total) std::cout << "Yes" ;
    else std::cout << "No";
    
    return 0 ;
}