#include <iostream>

int grid[301][301] ;
int s[301][301] ;
int sol = 0 ;

int main(){

	int m ; int n;
	scanf("%d %d", &m, &n);

	for(int i= 1 ; i <= m ; i++){
		for(int j = 1 ; j <= n ; j++){
			scanf("%d", &grid[i][j]);
		}
	}

  for(int sy = 1 ; sy<= m ; sy++)
   for(int sx = 1 ; sx <= n ; sx++)
			for(int i = sy ; i <= m ; i++){
				for(int j = sx ; j <= n ; j++){
							
					s[i][j] = grid[i][j];

					if(i != sy)
						s[i][j] += s[i-1][j];
					if(j != sx)
						s[i][j] += s[i][j-1];
					if(i != sy && j != sx)
						s[i][j] -= s[i-1][j-1];
		
					if(s[i][j] == 10){
						sol += 1 ;
						break; 
					} else if(s[i][j] > 10){
						break;
					} 
				}
			}

	std::cout << sol << std::endl;	

	return 0;
}