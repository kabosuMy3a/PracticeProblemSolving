#include <iostream>
int N ;
long long oil_prices[100000];
long long dist[99999];
long long ans = 0 ;

int main(){
	
	std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);
	std::cin >> N ;
	for(int i = 0 ; i < N-1 ; i++) std::cin >> dist[i];
	for(int i = 0 ; i < N ; i++) std::cin >> oil_prices[i];
	
	long long min_price = oil_prices[0] ;
	for(int i = 0 ; i < N-1 ; i++){
		if(min_price > oil_prices[i]) min_price = oil_prices[i];
		ans += dist[i] * min_price ;
	}	

	std::cout << ans << "\n";
	return 0;
}
