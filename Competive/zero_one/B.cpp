#include <iostream>

long double N, K ;
long long ans ;

int main(){

	std::cin >> N >> K;

	if(K == 1){
		std::cout << -1 << "\n";
		return 0 ;
	}
	long double X = N * K / (K - 1);
	
	if(X != (long long) X) 
		ans = (long long)X + 1;
	else 
		ans = (long long)X ;
	

	std::cout << ans << "\n";


	return 0 ;
}