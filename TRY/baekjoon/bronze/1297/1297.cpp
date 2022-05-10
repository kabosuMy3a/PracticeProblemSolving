#include <iostream>
#include <cmath>

int main () {
    int r, a, b ; std::cin >> r >> a >> b ;
    double coef = (double)(r * r) / (double)((a * a) + (b * b)) ;
    coef = sqrt(coef);
    std::cout << coef << "\n" ;
    std::cout << (int)(a * coef) << " ";
    std::cout << (int)(b * coef) ;  
    return 0 ;
}
