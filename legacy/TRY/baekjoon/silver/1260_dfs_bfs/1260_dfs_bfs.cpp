:#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>

int graph[1001][1001] = {0} ;
int N ; int M ; int start ;
int visited[1001];
std::queue<int> bfs_q ;
std::stack<int> dfs_s ;


int main(){
	std::cin >> N >> M >> start ;
	for(int i = 0 ; i < M ; i++){
		int a, b ; std::cin >> a >> b;
		graph[a][b]= 1;
		graph[b][a]= 1;
	}

	memset(visited, 0, sizeof(int) * N+1);
	dfs_s.push(start);

	while(!dfs_s.empty()){
		int cur = dfs_s.top();
		dfs_s.pop();
		if(visited[cur]) continue;
		visited[cur] = 1;
		std::cout << cur << " ";
		for(int i = N ; i >= 1 ; i--){
			if(!visited[i] && graph[cur][i] == 1){
				dfs_s.push(i);
			}
		}
	}
	std::cout << "\n";

	memset(visited, 0, sizeof(int) * N+1);
	bfs_q.push(start);
	visited[start] = 1;

	while(!bfs_q.empty()){
		int cur = bfs_q.front();
		bfs_q.pop();
		std::cout << cur << " ";
		for(int i = 1 ; i <= N ; i++){
			if(!visited[i] && graph[cur][i] == 1){
				bfs_q.push(i);
				visited[i] = 1;
			}
		}
	}
	std::cout << "\n";



	return 0 ;
}
