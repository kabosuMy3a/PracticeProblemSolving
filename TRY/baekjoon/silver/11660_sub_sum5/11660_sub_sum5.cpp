#include <iostream>

int table[1025][1025] ;
int dp[1025][1025] ;
int N, M ;

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);

	std::cin >> N >> M ; 
	for(int i = 0 ; i <= N ; i++){
		for(int j = 0 ; j <= N ; j++){
			if(i == 0 || j == 0){
				table[i][j] = 0 ; dp[i][j] = 0;
				continue ;
			}
			int a ; std::cin >> a ;
			table[i][j] = a ;
			dp[i][j] = table[i][j] - dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1]  ;
		}
	}

	for(int i = 0 ; i < M ; i++){
		int a, b, c, d ;
		std::cin >> a >> b >> c >> d ;
		std::cout << dp[c][d] - dp[c][b-1] - dp[a-1][d] + dp[a-1][b-1] << "\n" ;
	}
	
	return 0 ;
}