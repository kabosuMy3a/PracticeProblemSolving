#include <iostream>
#include <queue>
#include <utility>

int N, M ;
int init_map[8][8] ;
int cur_map[8][8] ;

int make_cur_map(int a, int b, int c){

}

int bfs(int start){
	std::queue<std::pair<int,int>> q;

	int visited[8][8] = {0,} ; 
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(visited[i][j]) continue ;
			if(cur_map[i][j] == 2) q.push({i,j}); 
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);
	std::cin >> N >> M :
	for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) std::cin >> lab_map[i][j] ;


	return 0 ;
}