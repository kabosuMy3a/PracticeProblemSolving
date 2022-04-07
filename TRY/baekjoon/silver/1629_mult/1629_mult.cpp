#include <iostream>
long long a, c; 
long long fow(long long b){
    if(b == 1) return a % c ;
    if(b == 0) return 1 ;
    
    long long rst = fow(b/2) % c ; 
    if(b % 2 == 0) return (rst * rst) % c ;
    else return ((rst * rst) % c * (a % c)) % c ;

}

int main(){
    
    long long b ; std::cin >> a >> b >> c;
    std::cout << fow(b) % c <<  "\n" ; 
    return 0 ; 
}