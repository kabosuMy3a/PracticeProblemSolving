#include <iostream>
#include <queue>
#include <cstring>
#include <cassert>

std::vector<int> graph[101] ;
int graph_rank[101];
std::queue<int> traverse_queue ;
int N ; int M ;
int min_kevin_bacon = 10001 ;
int min_kevin_bacon_idx = -1 ;

int main(){

	std::cin >> N >> M;

	for(int i = 0 ; i < M ; i++){
		int a, b ; std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 1 ; i <= N ; i++){
		memset(graph_rank, -1, (N+1) * sizeof(int));
		int num_kevin_bacon = 0 ;
		traverse_queue.push(i);
		graph_rank[i] = 0 ;

		while(!traverse_queue.empty()){
			int cur = traverse_queue.front();
			traverse_queue.pop();
			for(auto a : graph[cur]){
				if(graph_rank[a] != -1) continue ;
				graph_rank[a] = graph_rank[cur] + 1 ;
				num_kevin_bacon += graph_rank[a];
				traverse_queue.push(a);
			}
		}

		if(min_kevin_bacon > num_kevin_bacon) {
			min_kevin_bacon = num_kevin_bacon ;
			min_kevin_bacon_idx = i ;
		}
	}

	std::cout << min_kevin_bacon_idx << std::endl;

	return 0 ;
}