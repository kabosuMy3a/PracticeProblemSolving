#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

std::string s ;
int ans[1000000] ;

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0); std::cout.tie(0x0);
	int N ; std::cin >> N ;
	memset(ans, 0, sizeof(int) * N);

	for(int i = 0 ; i < N ; i++){
		std::cin >> s;
		int mult = 1 ;
		for(auto c : s){
			int a = c - '0';
			ans[i] += a * mult;
			mult *= 10 ;
		}
	}

	std::sort(ans, ans+N);
	for(int i = 0 ; i < N  ; i++){
		std::cout << ans[i] << "\n";
	}

	return 0;
}