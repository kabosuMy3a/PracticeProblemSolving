#include <iostream>
#include <vector>
#include <stack>

int graph[100][100] ;
int ans[100][100] ;
int visited[100] ;

int N ; 
//std::vector<int> path ;

void dfs(int origin, int cur){
	//path.push_back(cur);
	visited[cur] = 1 ;

	for(int i = 0 ; i < N ; i++){
		if(!graph[cur][i]) continue ;

		//for(auto prev : path){
		//	ans[prev][i] = 1 ;
		//}
		ans[origin][i] = 1 ;

		if(visited[i]){
			continue ;
		}
		visited[i] = 1 ;
		dfs(origin, i);
	}
	
	//std::cout << cur << ": " ;
	//for(auto p : path){
	//	std::cout << p << " " ;
	//}
	//std::cout << "\n";
	//path.pop_back();

}

int main(){
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		visited[i] = 0 ;

		for(int j = 0 ; j < N ; j++){
			std::cin >> graph[i][j] ;
			ans[i][j] = 0 ; 
		}
	}

	for(int i = 0 ; i < N  ; i++){
		//if(visited[i]) continue ;
		//path.clear();
		for(int i = 0 ; i < N ; i++){
			visited[i] = 0 ;
		}
		dfs(i, i);
	}

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			std::cout << ans[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0 ;
}