#include <iostream>

int N ;
int grid[100][100];
int visited[100][100];
int rr[4] = {1,-1,0,0};
int cc[4] = {0, 0, 1, -1};
int ans = 0;

void dfs(int i, int j, int cur_color, int is_cow){
	visited[i][j] = 1;
	for(int k = 0 ; k < 4 ; k++){
		int nr = i + rr[k];
		int nc = j + cc[k];

		if(nr < 0 || nr >= N) continue ; 
		if(nc < 0 || nc >= N) continue ;
		if(visited[nr][nc]) continue ;		
		if(is_cow){
			if(cur_color == 2 && cur_color != grid[nr][nc]) continue ;
			if((cur_color == 0 || cur_color == 1) && grid[nr][nc] == 2) continue;
		} else {
			if(cur_color != grid[nr][nc]) continue ;
		}

		dfs(nr,nc,cur_color, is_cow);
	}
}

int main(){
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){ 
		for(int j = 0 ; j < N ; j++){
			char c ; std::cin >> c ;
			if(c == 'R') grid[i][j] = 0 ;
			else if(c == 'G') grid[i][j] = 1;
			else grid[i][j] = 2 ;
			visited[i][j] = 0 ;
		}
	}


	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(visited[i][j]) continue ;
			dfs(i, j, grid[i][j],0);
			ans++;
		}
	}
	std::cout << ans << " " ; ans = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			visited[i][j] = 0;
		}
	}

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(visited[i][j]) continue ;
			dfs(i, j, grid[i][j], 1);
			ans++;
		}
	}
	std::cout << ans << "\n";

	return 0;
}