#include <iostream>
#include <vector>

int N ;
std::vector<int> tree[100001] ;
int min_cost_coloring_sub_tree[100001][21];

int dfs(int cur, int prev, int prev_color){
	if(tree[cur].size() == 1 && prev_color != 0){
		if(prev_color == 1) return 2 ;
		else return 1 ;
	}

	if(min_cost_coloring_sub_tree[cur][prev_color] != 0){
		//std::cout << cur << " " << prev_color << " " << min_cost_coloring_sub_tree[cur][prev_color] << "\n";
		return min_cost_coloring_sub_tree[cur][prev_color] ;
	}

	int rst = 20 * 100005 ;
 	for(int i = 1 ; i <= 20 ; i++){
 		if(i == prev_color) continue ;
 		int a = 0 ;
 		for(auto next : tree[cur]){
 			if(next == prev) continue ;
 			a += dfs(next, cur, i);
 		}
		if(rst > a + i) rst = a + i ;
	}
	min_cost_coloring_sub_tree[cur][prev_color] = rst ;
	return rst ;
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N;
	if(N == 1){
		std::cout << 1 << "\n";
		return 0 ;
	}
	for(int i = 0 ; i < N -1 ; i++){
		int a, b ; std::cin >> a >> b;
		tree[a].push_back(b) ;
		tree[b].push_back(a) ;
		for(int j = 0 ; j <= 20 ; j++){
			min_cost_coloring_sub_tree[i][j] = 0 ;
		}
	}

	std::cout << dfs(1, 0, 0) << "\n";
	return 0 ;
}