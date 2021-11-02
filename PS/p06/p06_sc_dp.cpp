#include <iostream>
#include <cstring>
#include <climits>

int cables[500] ;
int cables_sum[500][500] ;
int cables_dp[500][500] ;

int calculate(int f, int r){
	if(cables_dp[f][r] != -1)
		return cables_dp[f][r] ;
	
	if(f + 1 == r){
		cables_dp[f][r] = cables_sum[f][r];
		return cables_dp[f][r]; 
	}

	int dp_min = INT_MAX;
	for(int i = f ; i < r ; i++){
		int cur = calculate(f, i) + calculate(i+1,r) ;
		if(cur < dp_min) dp_min = cur ;
	}
	cables_dp[f][r] = dp_min + cables_sum[f][r];
	return cables_dp[f][r] ;
}

int main(){

	memset(cables_dp, -1, sizeof(cables_dp));
	int N ; std::cin >> N;
	
	for(int i = 0 ; i < N ; i++){ 
		int a ; std::cin >> a ;
		cables[i] = a ;

		cables_sum[i][i] = a ;
		for(int j = 0 ; j < i ; j++)
			cables_sum[j][i] = (a + cables_sum[j][i-1]);

		cables_dp[i][i] = 0 ; 
	}

	std::cout << calculate(0, N-1) << std::endl;

	return 0 ;
}