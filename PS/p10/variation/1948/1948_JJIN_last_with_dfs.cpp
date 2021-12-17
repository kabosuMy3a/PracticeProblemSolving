#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <cstring>
#include <cassert>

int N ; int M ;
std::vector<std::pair<int, int>> airworks[10001];
int weights_max_after_this_city[10001] ;

int max_weight = 0 ;
std::set<std::pair<int, int>> ans_path_set ;

int dfs(int weight, int id){
	if(weights_max_after_this_city[id] != -1){
		if(weight + weights_max_after_this_city[id] >= max_weight){
			max_weight = weight + weights_max_after_this_city[id];
		} 
		return weights_max_after_this_city[id] ; 
	}

	if(airworks[id].empty()){
		if(weight >= max_weight){
			max_weight = weight ;
		}
		weights_max_after_this_city[id] = 0 ;
		return 0 ;
	}
	
	int max_next_available = 0 ;
	for(auto a : airworks[id]){
		int next_weight = weight + a.second ;
		int next_available = dfs(next_weight, a.first) + a.second ;
		if(max_next_available < next_available) max_next_available = next_available ;

	}
	weights_max_after_this_city[id] = max_next_available ;
	return max_next_available ;
		
}

int is_registered_path[10001] ;

void register_path(int until_weight, int cur){
	if(is_registered_path[cur]) return ;
	if(airworks[cur].empty()) return ;

	is_registered_path[cur] = 1 ;

	for(auto next : airworks[cur]){
		int next_weight = until_weight + next.second ;
		int available = next_weight + weights_max_after_this_city[next.first];
		if(available != max_weight) continue;
		std::pair<int, int> registering_edge = std::make_pair(cur, next.first);
		ans_path_set.insert(registering_edge);
		register_path(next_weight, next.first);
	}
}

int main() {
	memset(weights_max_after_this_city, -1, sizeof(weights_max_after_this_city));
	memset(is_registered_path, 0, sizeof(is_registered_path));
	std::cin >> N ; 
	std::cin >> M ;
	
	for(int i = 0 ; i < M ; i++){
		int a, b, w ;
		std::cin >> a ;
		std::cin >> b ;
		std::cin >> w ;
		airworks[a].push_back(std::make_pair(b,w));
	}	

	int st ; int ed;  
	std::cin >> st ;
	std::cin >> ed ;

	dfs(0, st);
	register_path(0, st);

	std::cout << max_weight << std::endl;
	std::cout << ans_path_set.size() << std::endl;
	
	return 0;
}