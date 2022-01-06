#include <iostream>

int N ; int K ;

int main(){

	std::cin >> K >> N ;

    if(K == 0 && N % 6 == 1) std::cout << "HS" << "\n";
    if(K == 1 && N % 6 == 1) std::cout << "YG" << "\n";
    if((N % 6 >= 2) && (N % 6 <= 4)) std::cout << "YG" << "\n";
    if(K == 0 && (N % 6 == 5 || N % 6 == 0)) std::cout << "YG" << "\n";
    if(K == 1 && (N % 6 == 5 || N % 6 == 0)) std::cout << "HS" << "\n";

	return 0 ; 
}