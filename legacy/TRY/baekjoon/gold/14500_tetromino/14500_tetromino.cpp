#include <iostream>
#include <vector>

int N, M ; int board[500][500];
int next_r[19][4] = 
{
	{0,0,0,0}, {0,1,2,3}, 
	{0,0,1,1}, 
	{0,1,2,2}, {0,1,2,2}, {0,0,0,1}, {0,0,0,1}, 
	{0,0,1,2}, {0,0,1,2}, {0,0,0,-1}, {0,1,1,1},
	{0,1,1,2}, {0,1,1,2}, {0,0,-1,-1}, {0,0,1,1},
	{0,0,0,1}, {0,0,-1,1}, {0,0,-1,0}, {0,1,1,2}
}; 
int next_c[19][4] =
{
	{0,1,2,3}, {0,0,0,0}, 
	{0,1,0,1}, 
	{0,0,0,1}, {0,0,0,-1}, {0,1,2,0}, {0,1,2,2},
	{0,1,1,1}, {0,1,0,0}, {0,1,2,2}, {0,0,1,2},
	{0,0,1,1}, {0,0,-1,-1}, {0,1,1,2}, {0,1,1,2},
	{0,1,2,1}, {0,1,1,1}, {0,1,1,2}, {0,0,1,0}
};

void verify(){
	for(int k = 0 ; k < 19 ; k++){
		int nr = 1; int nc= 1;
		int sb[5][5] = {0,} ;
		for(int i = 0 ; i < 4 ; i++){
			nr = 1 + next_r[k][i];
			nc = 1 + next_c[k][i];
			sb[nr][nc] = 1 ;
		}
		std::cout << k << "\n";
		for(int i = 0 ; i < 5 ; i++){
			for(int j = 0 ; j < 5 ; j++){
				std::cout << sb[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}	
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N >> M ;
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < M ; j++)
			std::cin >> board[i][j];

	//verify();
    int max_score = -1 ;
	for(int n = 0 ; n < N ; n++){
		for(int m = 0 ; m < M ; m++){
			for(int k = 0 ; k < 19 ; k++){
				int sum = 0;
				for(int i = 0 ; i < 4 ; i++){
					int nr = n + next_r[k][i]; 
					int nc = m + next_c[k][i];
					if(nr < 0 || nr >= N) continue ;
					if(nc < 0 || nc >= M) continue ;
					sum += board[nr][nc];
				}
				if(sum > max_score) max_score = sum ;
			}
		}
	}

	std::cout << max_score << "\n";

	return 0 ;
}