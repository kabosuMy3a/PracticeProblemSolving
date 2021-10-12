#include <iostream>

int grid[301][301] = {0} ;
int sol = 0 ;

int main(){

	int m ; int n;
	scanf("%d %d", &m, &n);

	for(int i= 1 ; i <= m ; i++){
		for(int j = 1 ; j <= n ; j++){
			scanf("%d", &grid[i][j]);
		}
	}

	for(int k = 1 ; k <= m * n ; k++){
		int sy = k / n + 1;
		int sx = k % n ;
		if(sx == 0 ){
			sy -= 1 ;
			sx += n;
		}

		int total_sum[301] = {0} ;
		for(int i = sy ; i <= m ; i++){
			int x_sum[301] = {0}; 
			for(int j = sx ; j<=n ; j++){
				x_sum[j] = x_sum[j-1] + grid[i][j];
				total_sum[j] += x_sum[j] ; 
				if(total_sum[j] == 10){
					sol += 1 ;
					break; 
				} else if(total_sum[j] > 10){
					break;
				} 
			}
		}
	}

	std::cout << sol << std::endl;	

	return 0;
}