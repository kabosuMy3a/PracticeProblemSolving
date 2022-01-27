#include <iostream>

int N, M ;
int bridge[1001][1001];
long long num_way[1001][1001];
long long modi = 1000000007 ;

int main(){
	std::ios_base::sync_with_stdio(0x0);
    
	std::cin >> N >> M ;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= M ; j++){
			std::cin >> bridge[i][j];
			num_way[i][j] = 0 ;
		}
	}
	
	for(int i = 1 ; i <= M ; i++){
		if(bridge[N][i] == 1) num_way[N][i] = 1 ;
	}

	for(int i = N - 1 ; i >= 1 ; i--){
		for(int j = 1 ; j <= M ; j++){
			if(bridge[i][j] == 0) continue ;
			long long a = 0 ; long long b = 0 ; long long c = 0;
			if(j != 1) a = num_way[i+1][j-1] ;
			b = num_way[i+1][j] ;
			if(j != M) c = num_way[i+1][j+1] ;
			num_way[i][j] = a + b + c ;
            num_way[i][j] %= modi ;
		}
	}
	/*
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= M ; j++)
			//std::cout << bridge[i][j] << " ";
			std::cout << num_way[i][j] << " ";
		std::cout << "\n";
	}*/

	long long ans = 0 ;
	for(int i = 1 ; i <= M ; i++){
		ans += num_way[1][i] ;
        ans %= modi ;
	}

	std::cout << ans << "\n";

	return 0 ;
}