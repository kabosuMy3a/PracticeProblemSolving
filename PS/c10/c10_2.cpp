#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int N ;
std::pair<long, long> buildings[50000] ;
std::vector<int> dependency_tree[50000] ; 
int tree_color[50000]; 
#define WHITE -1
#define RED 0
#define BLACK 1

bool is_dependency(std::pair<long, long> l_b, std::pair<long, long> r_b){
	long long x_dist = r_b.first - l_b.first ;
	long long y_dist = r_b.second -l_b.second ;	
	return (x_dist * x_dist + y_dist * y_dist) <= 25 ;
}

int main(){

	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int x, y;
		std::cin >> x >> y;
		buildings[i] = std::make_pair(x, y);
	}

	std::sort(buildings, buildings+N);

	for(int i = 1 ; i < N ; i++){
		std::pair<long, long> cur = buildings[i];
		for(int j = i-1 ; j >= 0 ; j--){
			std::pair<long, long> prev = buildings[j];
			if((cur.first - prev.first) > 5) break ;
			if(is_dependency(prev, cur)){ 
				dependency_tree[i].push_back(j);
				dependency_tree[j].push_back(i);
			}
		}
	}

	memset(tree_color, WHITE, sizeof(int) * N);
	std::queue<int> tree_traverse_queue ;

	int num_colors[2] = {0,0} ;
	int pizza = 0 ;
	for(int i = 0 ; i < N ; i++){
		if(tree_color[i] == WHITE){
			tree_traverse_queue.push(i);
			tree_color[i] = RED ;
			num_colors[0] += 1;
 		} else {
			continue ;
		}
		while(tree_traverse_queue.size() != 0){
			int cur = tree_traverse_queue.front();
			tree_traverse_queue.pop();
			if(dependency_tree[cur].size() == 0) continue ;
			for(int j = 0 ; j < dependency_tree[cur].size() ; j++){
				int next = dependency_tree[cur][j];
				if(tree_color[next] == WHITE){
					tree_traverse_queue.push(next);
					tree_color[next] = tree_color[cur] ^ 1 ; 
					num_colors[tree_color[next]] += 1; 
				}
			}
 		}

 		pizza += std::min(num_colors[0], num_colors[1]);
 		num_colors[0] = 0 ; num_colors[1] = 0;
	}

	std::cout << pizza << std::endl;
	return 0 ; 
}