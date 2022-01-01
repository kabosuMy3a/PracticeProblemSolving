#include <iostream>

int main(){

	int T ; std::cin >> T;
	for(int t = 1 ; t <= T ; t++){
		long long N, K, S ;
		std::cin >> N >> K >> S;
		long long go_back = K + (K-S) + (N - S) ;
		long long reset = K + N ;
		long long ans = (go_back > reset) ? reset : go_back ; 
		std::cout << "Case #" << t << ": " << ans << "\n";
	}


	return 0 ; 
}