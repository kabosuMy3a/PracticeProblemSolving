#include <iostream>
#include <queue>
#include <utility>

int field[50][50];
int next_r[4] = {-1,1,0,0};
int next_c[4] = {0,0,-1,1};

int main(){

	std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);

	int T ; std::cin >> T ;
	for(int t = 0 ; t < T ; t++){
		
		int R, C, K; std::cin >> R >> C >> K;
		int ans = 0;
		
		for(int i = 0 ; i < R ; i++)
			for(int j = 0 ; j < C ; j++)
				field[i][j] = 0 ;

		for(int i = 0 ; i < K ; i++){
			int r, c ; std::cin >> r >> c ;
			field[r][c] = 1 ;
		}

		std::queue<std::pair<int,int>> bfs_q ;		
		for(int i = 0 ; i < R ; i++){
			for(int j = 0 ; j < C ; j++){
				if(field[i][j] != 1) continue ;
				field[i][j] += 2 ;
				bfs_q.push({i,j});
				while(!bfs_q.empty()){
					std::pair<int, int> cur = bfs_q.front();
					bfs_q.pop();
					int r = cur.first; int c = cur.second ;

					for(int h = 0 ; h < 4 ; h++){
						int nr = r + next_r[h];
						int nc = c + next_c[h];
						if(nr < 0 || nr >= R) continue ;
						if(nc < 0 || nc >= C) continue ;
						if(field[nr][nc] == 1){
							bfs_q.push({nr,nc});
						}
						field[nr][nc] += 2 ;
					}
				}
				ans+= 1;
			}
		}

		for(int i = 0 ; i < R ; i++){
			for(int j = 0 ; j < C ; j++){
				std::cout << field[i][j] << " ";
			}
			std::cout << "\n";
		}
	

		std::cout << ans << "\n";
	}
	
	return 0;
}