#include <iostream>
#include <algorithm>

int N ;
int wines[10001] ;
int max_wines[10001];

int main(){
	
	std::cin >> N ;
	for(int i = 1 ; i <= N ; i++) std::cin>> wines[i] ;
	max_wines[0] = 0 ;
	max_wines[1] = wines[1] ;
	max_wines[2] = wines[1] + wines[2] ;

	for(int i = 3 ; i <= N ; i++){
		max_wines[i] = std::max(max_wines[i-1], wines[i] + max_wines[i-2]) ;
		max_wines[i] = std::max(max_wines[i], wines[i] + wines[i-1] + max_wines[i-3]);
	}

	std::cout << max_wines[N] << "\n";
	return 0 ;
}