#include <iostream>

unsigned long long N ;
int main(){
	std::cin >> N ; unsigned long long bound = 1;
	while(true){
		if(bound > N) break;
		bound *= 2 ;
	}
	unsigned long long a = (bound - 1) ^ N ;
	if(a == 0){
		std::cout << 1 << "\n";
		std::cout << N << "\n";
	} else {
		std::cout << 2 << "\n";
		std::cout << a << "\n";
		std::cout << N << "\n";
	}

	return 0;
}