#include <iostream>
#include <cmath>

int main(){
    long double a ; std::cin >> a ;
    long double side = sqrt(a);
    std::cout.precision(25);
    std::cout << side * 4 ;

    
    return 0; 
}