#include <iostream>
#include <algorithm>

int N;
long long tower[1000001] ; 

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N ; 
    if(N == 1){
        std::cin >> N;
        std::cout << N ;
        return 0 ;
    }

	for(int i = 1 ; i <= N ; i++) std::cin >> tower[i];
	long long max_height = std::max(tower[1], tower[N]) ;
	if(N == 2){
		std::cout << max_height ;
		return 0 ;
	}

	for(int i = 2 ; i <= N-1 ; i++){
		long long cur_max = tower[i] + std::min(tower[i-1], tower[i+1]);
		if(cur_max > max_height) max_height = cur_max ;
	}
	std::cout << max_height ;
	return 0;
}