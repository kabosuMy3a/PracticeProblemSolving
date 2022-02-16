#include <iostream>
#include <vector>
#include <utility>

int N ;
std::vector<std::pair<int,int>> tree[100001];


std::pair<int,int> find_longest_node(int cur, int prev){
	if(prev != 0 && tree[cur].size() == 1) return {cur, 0} ;

	int max_w = -1 ; int longest_node ;
	for(auto next : tree[cur]){
		if(next.first == prev) continue ;
		auto a = find_longest_node(next.first, cur) ;
		a.second += next.second ;
		if(max_w < a.second){
			longest_node = a.first;
			max_w = a.second ;
		}
	}
	return {longest_node, max_w}; 
}

int main(){

	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int from, to, weight ;
		std::cin >> from ;
		while(1){
			std::cin >> to ;
			if(to != -1){
				std::cin >> weight ;
				tree[from].push_back({to, weight});
			} else break; 
		}
	}

	auto next_node = find_longest_node(1, 0) ;
	auto ans = find_longest_node(next_node.first, 0);
	std::cout << ans.second << "\n";

	return 0;

}