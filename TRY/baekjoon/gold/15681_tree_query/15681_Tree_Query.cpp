#include <iostream> 
#include <vector>
#include <cstring>
#include <cassert>

int N ; int R ; int Q ;
std::vector<int> tree[100001] ;
int tree_visited[100001];
int num_children_of_leaf[100001];

int traverse(int leaf){
	tree_visited[leaf] = 1 ;
	for(auto child : tree[leaf]){
		if(!tree_visited[child]){
			num_children_of_leaf[leaf] += traverse(child) + 1;
		}
	}
	return num_children_of_leaf[leaf] ;
}

int main(){

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	memset(num_children_of_leaf, 0, N * sizeof(int));
	memset(tree_visited, 0, N * sizeof(int));


	std::cin >> N >> R >> Q ;
	for(int i = 0 ; i < N -1 ; i++){
		int a, b ; std::cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}	
	/*
	for(int i = 0 ; i < N ; i++){
		std::cout << i << "| " ;
		for(auto child : tree[i]){
			std::cout << child << " " ; 
		}
		std::cout << std::endl;
	}*/
	
	traverse(R);

	for(int i = 0 ; i < Q ; i++){
		int sub_root ; std::cin >> sub_root ;
		std::cout << num_children_of_leaf[sub_root] + 1 << "\n" ;
	}

	return 0 ;
}