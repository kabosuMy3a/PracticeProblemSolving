#include <iostream>
#include <queue>
#include <utility>

int field[300][300] ;
int r[8] = {-2,-2,-1,-1,1,1,2,2} ;
int c[8] = {1,-1,2,-2,2,-2,1,-1} ;

int main(){
	
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0); int T ; std::cin >> T ; 
	for(int t = 0 ; t < T ; t++){
		int N ; std::cin >> N;
		int cur_x , cur_y, dest_x, dest_y ;
		std::cin >> cur_x >> cur_y >> dest_x >> dest_y ;
		
		for(int i = 0 ; i < N ; i++)
			for(int j = 0 ; j < N ;j++) field[i][j] = -1 ;

		std::queue<std::pair<int,int>> bfs_q ;
		bfs_q.push({cur_x,cur_y});
		field[cur_x][cur_y] = 0 ;

		while(!bfs_q.empty()){
			std::pair<int,int> cur = bfs_q.front();
			bfs_q.pop();
			if(cur.first == dest_x && cur.second == dest_y){
				std::cout << field[dest_x][dest_y] << "\n";
				break;
			}

			for(int i = 0 ; i < 8 ; i++){
				int next_x = cur.first + r[i];
				int next_y = cur.second + c[i];

				if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < N){
					if(field[next_x][next_y] == -1){
						bfs_q.push({next_x, next_y});
						field[next_x][next_y] = field[cur.first][cur.second] + 1;
					}
				}
			}
		}
	}

	return 0;
}