#include <iostream>
#include <vector>
#include <algorithm>

long long N, M ;
long long prime_num[25];

long long ans = 0;

int main(){

	std::cin >> N >> M ;
	for(int i = 0 ; i < N ; i++) std::cin >> prime_num[i] ;

	for(int i = 1 ; i <= N ; i++){
		std::vector<int> permu ; 

		for(int j = 1 ; j <= N ; j++){
			if(j <= i) permu.push_back(0);
			else permu.push_back(1);
		}

		do {
			long long cur = 1; 
			for(int j = 0 ; j < N ; j++) if(permu[j] == 0) cur *= prime_num[j] ;
			cur = M / cur ;
			if(i % 2 == 0) cur *= -1 ;
			ans += cur ;

		} while(std::next_permutation(permu.begin(), permu.end())) ;
	}

	std::cout << ans << "\n";

	return 0 ;
}