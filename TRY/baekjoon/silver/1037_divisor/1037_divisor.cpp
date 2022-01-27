#include <iostream>
#include <algorithm>

int main(){

	std::ios_base::sync_with_stdio(0x0);
	int N ; std::cin >> N;
	
	int min_div = 1000001 ; int max_div = 1 ;
	for(int i = 0 ; i < N ; i++){
		int a ; std::cin >> a;
		max_div = (max_div < a) ? a : max_div ;
		min_div = (a < min_div ) ? a : min_div ;
	}
	
	std::cout << max_div * min_div << "\n" ;
	return 0 ;
}