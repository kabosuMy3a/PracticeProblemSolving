#include <iostream>

int N, K ;

int main(){
	std::cin >> N >> K ;

	if(K >= 2 && K <= 4){
		std::cout << "YG" << "\n";
		return 0 ;
	}

	if((K-1) % 4 == 0){
		int a = (K-1)/4 ;
		if(a % 2 == 0){
			if(N == 1){
				std::cout << "YG" << "\n";
			} else {
				std::cout << "HS" <<  "\n";
			}
		} else {
			if(N == 0){
				std::cout << "YG" << "\n" ;
			} else {
				std::cout << "HS" << "\n";
			}
		}
	} else {
		int a = (K-1)/4 ;
		int b = (K-1)%4 ;
		if(a % 2 == 0){
			if((b + N) % 2 == 0){
				std::cout << "YG" << "\n" ;
			} else {
				std::cout << "HS" << "\n" ;	
			}
		} else {
			if((b + N) % 2 == 1){
				std::cout << "YG" << "\n" ;
			} else {
				std::cout << "HS" << "\n" ;	
			}
		}
	}

	return 0 ;


}