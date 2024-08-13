#include <iostream>
#include <algorithm>

int N, K ;
int max_value_by_weights[2][100001];

int main(){
    std::ios_base::sync_with_stdio(0x0);
	std::cin >> N >> K ;
	for(int i = 0 ; i <= K ; i++) max_value_by_weights[1][i] = 0 ;
	for(int i = 0 ; i < N ; i++){
		int w, v ; std::cin >> w >> v ;
		int prev = (i % 2) ; int cur = (i % 2) ^ 1 ;
		for(int j = 0 ; j < w ; j++){
			max_value_by_weights[cur][j] = max_value_by_weights[prev][j]; 
		}
		for(int j = w ; j <= K ; j++){
			int put_in = max_value_by_weights[prev][j - w] + v ;
			int not_put_in = max_value_by_weights[prev][j] ;
			max_value_by_weights[cur][j] = std::max(put_in, not_put_in);
		}
		if(i == N - 1) std::cout << max_value_by_weights[cur][K] << "\n";
	}

	return 0 ;
}