#include <iostream> 
#include <cmath>

int T ; long long N ; 

int main(){
	std::cin >> T;

	for(int t = 0 ; t < T ; t++){
		std::cin >> N ;

		int flag = 0 ;
		for(int i = 1 ; i <= (long long)sqrt(N) + 1 ; i++){
			if(N % i != 0) continue ;
			long long a = i ;
			long long b = N/i  ;
			if((a + b) % 3 == 0){
				std::cout << "TAK" << "\n";
				flag = 1;
				break; 
			} 
		}
		if(!flag) std::cout << "NIE" << "\n";
	}

	return 0 ;
}