#include <iostream>
#include <queue>
#include <utility>
#include <vector> 

int N, M ; 
int city[1000][1000];
int processed[1000][1000] ;
int cost[1000][1000] ;

int next_r[4] = {-1,1,0,0} ;
int next_c[4] = {0,0,-1,1} ;

#define INF 1234567890

std::priority_queue<std::pair<int, std::pair<int,int>>/*, std::vector<std::pair<int, std::pair<int,int>>> , std::greater<int>>*/> min_pq ;


int main(){
	std::ios_base::sync_with_stdio(0x0); 
	std::cin >> N >> M ;
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < M ; j++)
			std::cin >> city[i][j] ;

	if(city[0][0] == -1 || city[N-1][M-1] == -1){
		std::cout << -1 << "\n";
		return 0 ;
	}

	/*
	min_pq.push({-3,{0,0}});
	min_pq.push({-1,{0,0}});
	min_pq.push({-2,{0,0}});
	std::pair<int, std::pair<int, int>> cur = min_pq.top();
	std::cout<< cur.first << " {" << cur.second.first << ", " << cur.second.second << "}\n" ;	
	*/


	for(int i = 0 ; i < 1000 ; i++){
		for(int j = 0 ; j < 1000 ; j++){
			processed[i][j] = 0;
			cost[i][j] = INF ;
		}
	}

	min_pq.push({city[0][0] * -1, {0,0}}); 
	cost[0][0]= city[0][0] ;


	while(!min_pq.empty()){
		std::pair<int, std::pair<int, int>> cur = min_pq.top();	min_pq.pop();
		std::pair<int, int> cur_p = cur.second ;
		if(processed[cur_p.first][cur_p.second]) continue ;
		processed[cur_p.first][cur_p.second] = 1 ;
		int cur_cost = cur.first * -1 ;

		for(int i = 0 ; i < 4 ; i++){
			int nr = cur_p.first + next_r[i] ;
			int nc = cur_p.second + next_c[i] ;
			if(nr < 0 || nr >= N) continue ;
			if(nc < 0 || nc >= M) continue ;
			if(city[nr][nc] == -1) continue ; 

			int relax = cost[cur_p.first][cur_p.second] + city[nr][nc] ;
			if(relax < cost[nr][nc]){
				cost[nr][nc] = relax ;
				min_pq.push({relax * -1, {nr,nc}});
			}
		}

	} 

	if(cost[N-1][M-1] == INF) std::cout << -1 <<"\n" ;
	else std::cout << cost[N-1][M-1] << "\n";

	return 0 ; 
}