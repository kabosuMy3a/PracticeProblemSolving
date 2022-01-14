#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

std::vector<std::pair<int, int>> adj_graph[200001];
int V, E, start ;
int distance[200001] ;
int processed[200001] ;


std::priority_queue<std::pair<int, int>> pq ;

int main(){

	std::cin >> V >> E >> start ;

	for(int i= 0 ; i < E ; i++){
		int u, v, w ;
		std::cin >> u >> v >> w ;
		adj_graph[u].push_back({v,w});
	}

	for(int i = 1 ; i <= V ; i++){
		distance[i] = INT_MAX ;
	}

	for(int i = 1 ; i <= V ; i++){
		processed[i] = 0 ;
	}

	distance[start] = 0 ;
	pq.push({start, 0});

	while(!pq.empty()){
		std::pair<int, int> cur = pq.top();
		pq.pop();
		if(processed[cur.first]) continue ;
		processed[cur.first] = 1 ;

		for(auto next : adj_graph[cur.first]){
			int nw = next.second ;
			int relax = nw + distance[cur.first];
			if(distance[next.first] > relax){
				distance[next.first] = relax ;
				pq.push({next.first, -distance[next.first]});
			}

		}
	}

	for(int i = 1 ; i <= V; i++){
		if(distance[i] == INT_MAX)
			std::cout<< "INF" << "\n";
		else 
			std::cout << distance[i] << "\n";
	}


	return 0 ;
}

