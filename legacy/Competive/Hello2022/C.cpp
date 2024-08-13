#include <iostream>

long long N ; long long K ;

int main(){

	std::cin >> N >> K ;
	long long total_time = 0 ;
	for(int i = 0 ; i < N ; i++){
		long long si ; std::cin >> si ;
		total_time += si ;
	}
	long long interval = K - total_time ;

	long long f = interval + N ;

	long long ans = 1 ; 
	for(int i = interval + 1 ; i <= f ; i++){
		ans *= (i % 1000000007);
		ans %= 1000000007 ;	
	}

	std::cout << ans << "\n";

	return 0;
}