#include <iostream>
#include <utility>
#include <vector>
#include <climits>
#include <queue>

std::vector<std::pair<int,int>> routes[1001] ;
int costs[1001];
int processed[1001];
int prevs[1001];

int main(){
	std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);

	int N, M ; std::cin >> N >> M ;
	for(int i = 0 ; i < M ; i++){
		int s, e, c ;
		std::cin >> s >> e >> c ;
		routes[s].push_back({c, e});
	}
	int root, summit ; std::cin >> root >> summit ;
	for(int i = 1 ; i <= N ; i++){
		costs[i] = INT_MAX ;
		processed[i] = 0 ;
		prevs[i] = -1 ;
	}
	costs[root] = 0 ;

	std::priority_queue<std::pair<int, int>> min_pq ; 
	min_pq.push({costs[root] * -1, root});

	while(!min_pq.empty()){
		std::pair<int,int> cur = min_pq.top(); min_pq.pop();
		if(processed[cur.second]) continue ;
		processed[cur.second] = 1 ;

		for(auto next : routes[cur.second]){
			int next_cost = (cur.first * -1) + next.first ;
			if(costs[next.second] > next_cost){
				prevs[next.second] = cur.second ;
				costs[next.second] = next_cost ;
				min_pq.push({next_cost * -1, next.second});
			}
		}
	}

	std::cout << costs[summit] << "\n";
	std::vector<int> ans ; int trace = summit ;
	while(1){
		if(trace == -1) break;
		ans.push_back(trace);
		trace = prevs[trace];
	}
	std::cout << ans.size() << "\n";
	for(auto it = ans.rbegin() ; it != ans.rend() ; it++){
		std::cout << *it << " " ;
	}



	return 0 ;
}