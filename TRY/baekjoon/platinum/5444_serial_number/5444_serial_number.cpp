#include <iostream>
#include <algorithm>

int num_guitar_by_modulo[2][100000]; 

int main(){

	std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);
	int T ; std::cin >> T ;
	for(int t = 0 ; t < T ; t++){
		int N, K ; std::cin >> N >> K ;
		for(int i = 0 ; i < K ; i++){
			num_guitar_by_modulo[0][i] = 0 ;
			num_guitar_by_modulo[1][i] = 0 ;
		}
		for(int i = 0 ; i < N ; i++){
			int cur = (i % 2) ; int prev = (i % 2) ^ 1 ;
			int si ; std::cin >> si ; si %= K ;
			int put_in = num_guitar_by_modulo[prev][0] + 1 ; 
			int not_put_in = num_guitar_by_modulo[prev][si] ;
			num_guitar_by_modulo[cur][si] = std::max(put_in, not_put_in) ;
			if(si != 0) num_guitar_by_modulo[cur][0] = num_guitar_by_modulo[prev][0] ;
			for(int j = 1 ; j < K ; j++) {
				int c = (si + j) % K ;
				if(num_guitar_by_modulo[prev][j] > 0){
					not_put_in = num_guitar_by_modulo[prev][c] ;
					put_in = num_guitar_by_modulo[prev][j] + 1 ;
					num_guitar_by_modulo[cur][c] = std::max(put_in, not_put_in) ;
				}
				num_guitar_by_modulo[cur][j] = std::max(num_guitar_by_modulo[cur][j], num_guitar_by_modulo[prev][j]);
			}

			if(i == N -1) std::cout << num_guitar_by_modulo[cur][0] << "\n" ;
		}
	}

	return 0 ;
}