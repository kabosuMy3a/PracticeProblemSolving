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

	for(int i = 1 ; i < N ; i++){
		long long left_price = oil_prices[i-1]; 
		long long right_price = oil_prices[i] ;
		int l_idx = i-1 ;
		while(left_price <= right_price && i < N){
			right_price = oil_prices[++i];
		}
		for(int j = l_idx ; j < i ; j++){
			ans += dist[j] * oil_prices[l_idx];
		}
	}	

	std::cout << ans << "\n";
	return 0;
}