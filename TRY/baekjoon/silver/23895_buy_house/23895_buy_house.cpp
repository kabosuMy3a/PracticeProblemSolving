#include <iostream>
#include <cstring>
#include <algorithm>

int houses[100000];

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cout.tie(0x0); std::cin.tie(0x0);

	int T ; std::cin >> T;
	for(int t = 1 ; t <= T ; t++){
		int N ; int B ;
		std::cin >> N >> B ;
		for(int i = 0 ; i < N ; i++){
			std::cin >> houses[i] ;
		}
		std::sort(houses, houses + N);

		int ans = 0 ;
		for(int j = 0 ; j < N ; j++){
			B -= houses[j];
			if(B >= 0) ans++ ;
			else break; 
		}
		memset(houses, 0, sizeof(int) * N);
		std::cout << "Case #" << t << ": " << ans << "\n";
	}

	return 0 ;
}