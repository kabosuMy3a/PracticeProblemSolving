#include <iostream>
#include <utility>
#include <queue>

int N ;
int sea[20][20] ;
int dist_from_shark[20][20] ;
std::pair<int, int> shark ;
int shark_lv = 2; int running_time = 0 ; int fish_eaten = 0 ;

int next_r[4] = {-1, 0, 0, 1};
int next_c[4] = {0, -1, 1, 0};

int main(){

	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			std::cin >> sea[i][j] ;
			if(sea[i][j] == 9){
				shark = {i,j};
				sea[i][j] = 0 ;
				dist_from_shark[i][j] = 0 ;
			} else {
				dist_from_shark[i][j] = -1 ;
			}
		}
	}

	std::queue<std::pair<int,int>> bfs_q ;
	while(1){
		std::queue<std::pair<int,int>> next_pos_q ;
		bfs_q.push(shark); int is_next_round_possible = 0 ;

		while(!bfs_q.empty()){
			std::pair<int, int> cur = bfs_q.front(); bfs_q.pop();
			for(int i = 0 ; i < 4 ; i++){
				int nr = cur.first + next_r[i] ;
				int nc = cur.second + next_c[i] ;
				if(nr < 0 || nr >= N) continue ;
				if(nc < 0 || nc >= N) continue ;
				if(dist_from_shark[nr][nc] != -1) continue ;				
				if(sea[nr][nc] > shark_lv) continue ;

				dist_from_shark[nr][nc] = dist_from_shark[cur.first][cur.second] + 1;
				bfs_q.push({nr,nc});
				if(sea[nr][nc] != 0 && sea[nr][nc] < shark_lv) next_pos_q.push({nr,nc});
			}
		}
			
		int dist ;
		if(!next_pos_q.empty()){
			shark = next_pos_q.front(); next_pos_q.pop();
			is_next_round_possible = 1 ;
			dist = dist_from_shark[shark.first][shark.second];
		}
		while(!next_pos_q.empty()){
			std::pair<int, int> ns = next_pos_q.front() ; next_pos_q.pop();
			if(dist < dist_from_shark[ns.first][ns.second]) break; 
			else{
				if(shark.first > ns.first){
					shark = ns ;
				} else if((shark.first == ns.first) && (shark.second > ns.second)){
					shark = ns ;
				}
			}
		}

		if(is_next_round_possible){
			running_time += dist_from_shark[shark.first][shark.second] ;

			for(int i = 0 ; i < N ; i++){
				for(int j = 0 ; j < N ; j++){
					dist_from_shark[i][j] = -1 ;
				}
			}
			dist_from_shark[shark.first][shark.second] = 0 ;
			sea[shark.first][shark.second] = 0 ;
			
			fish_eaten += 1;
			if(fish_eaten == shark_lv){
				fish_eaten = 0 ;
				shark_lv += 1 ; 
			}
		} else {
			std::cout << running_time << "\n";
			break;
		}
	}

	return 0;
}