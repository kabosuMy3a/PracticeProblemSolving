#include <iostream>
#include <queue>
#include <utility>

int R, C ;

int box[1000][1000] ;
std::queue<std::pair<int, int>> q ;
int adj_row[4] = {-1, 1, 0, 0};
int adj_col[4] = {0, 0, -1, 1};

int main(){

	std::cin >> C >> R ;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j  < C ; j++){
			int a ; std::cin >> a ;
			box[i][j] = a ;
			if(a == 1){
				q.push({i,j});
			}
		}
	}

	
	while(!q.empty()){
		std::pair<int, int> cur_tomato = q.front(); q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int nr = cur_tomato.first + adj_row[i] ; 
			int nc = cur_tomato.second + adj_col[i] ;
			if(nr < 0 || nr >= R) continue ;
			if(nc < 0 || nc >= C) continue ;
			if(box[nr][nc] == 0){
				box[nr][nc] = box[cur_tomato.first][cur_tomato.second] + 1;
				q.push({nr,nc});
			} 
		}
	}

	int ripen_max = 0 ;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ;  j < C ; j++){
			if(box[i][j] == 0){
				std::cout << -1 << "\n";
				return 0 ;
			} else {
				if(ripen_max < box[i][j]) ripen_max = box[i][j] ;
			}
		}
	}

	std::cout << ripen_max - 1 << "\n";


	return 0;
}