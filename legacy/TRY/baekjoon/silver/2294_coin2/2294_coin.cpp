#include <iostream>

int N, K ;
int coins[100];
int memo[10001];

int find_min_coins(int amount){

	//std::cout << amount << "\n";
	if(memo[amount] != 100000) return memo[amount];

	for(int i = 0 ; i < N ; i++){
		int c = amount - coins[i];
		if(c < 0) continue ;
		int mc = find_min_coins(c) ;
		if(mc == -1) continue ;
		if(mc + 1 < memo[amount]) memo[amount] = mc + 1;
	}

	if(memo[amount] == 100000) memo[amount] = -1 ;
	return memo[amount];

}

int main(){

	std::cin >> N >> K;
	for(int i = 0 ; i < N ; i++) std::cin >> coins[i] ;
	for(int i = 1 ; i <= K ; i++) memo[i] = 100000;
	memo[0] = 0 ;	

	find_min_coins(K);
	std::cout << memo[K] << "\n";

	return 0 ;
}