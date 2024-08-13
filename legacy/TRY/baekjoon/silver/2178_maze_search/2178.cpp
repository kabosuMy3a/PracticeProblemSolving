#include <iostream>
#include <queue>
#include <utility>

int maze[100][100] ;
int rank[100][100] ;

int next_r[4] = {-1,1,0,0};
int next_c[4] = {0,0,-1,1};

int main(){
	int R, C ; std::cin >> R >> C ;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			char a ; std::cin >> a ;
			maze[i][j] = a - '0' ;
			rank[i][j] = 0 ;
		}
	}

	std::queue<std::pair<int,int>> q ;
	q.push({0,0});
	rank[0][0] = 1 ;

	while(!q.empty()){
		std::pair<int,int> cur = q.front(); q.pop();

		for(int i = 0 ; i < 4 ; i++){
			std::pair<int,int> next = {cur.first + next_r[i], cur.second + next_c[i]};
			if(next.first < 0 || next.first >= R || next.second < 0 || next.second >= C) continue ;
			if(rank[next.first][next.second]) continue ;
			if(!maze[next.first][next.second]) continue ;

			q.push(next);
			rank[next.first][next.second] = rank[cur.first][cur.second] + 1 ;
		}
	}

	std::cout << rank[R-1][C-1];



	return 0 ;
}