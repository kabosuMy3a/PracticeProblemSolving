#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <cstring>


int N ; int M ;
std::vector<std::pair<int, long long>> airworks[10001];
long long visited[10001] ;

long long max_weight = 0 ;

std::vector<int> path ;
std::set<std::pair<int, int>> ans_path_set ;

long long dfs(long long weight, int id){

	path.push_back(id);

	if(visited[id] != -1){
		if(weight + visited[id] >= max_weight){
			max_weight = weight + visited[id];
			for(int j = 1 ; j < (int)path.size(); j++){
				std::pair<int,int> tmp = std::make_pair(path[j-1], path[j]);
				ans_path_set.insert(tmp);
			}
		} 

		path.pop_back();
		return visited[id] ; 
	}

	
	if((int)airworks[id].size() == 0){
		if(weight >= max_weight){
			max_weight = weight ;
			for(int j = 1 ; j < (int)path.size(); j++){
				std::pair<int,int> tmp = std::make_pair(path[j-1], path[j]);
				ans_path_set.insert(tmp);
			}
		}
		visited[id] = 0 ;
		path.pop_back();
		return 0 ;
	}
	
	long long max_next_available = 0 ;
	for(auto a : airworks[id]){
		long long next_weight = weight + a.second ;

		long long next_available = dfs(next_weight, a.first) + a.second ;
		if(max_next_available < next_available) max_next_available = next_available ;

	}
	
	path.pop_back();
	visited[id] = max_next_available ;
	return max_next_available ;
		
}

int main() {
	memset(visited, -1, sizeof(visited));
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

	//for(int i = 1 ; i <= N ; i++){
	if(visited[st] == -1) dfs(0, st);
  	//}

	std::cout << max_weight << std::endl;
	std::cout << ans_path_set.size() << std::endl;
	
	return 0;
}