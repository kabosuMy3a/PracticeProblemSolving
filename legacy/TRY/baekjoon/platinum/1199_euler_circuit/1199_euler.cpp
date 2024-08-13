#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int N ;
int graph[1001][1001] ;
int visited[1001][1001]; // graph를 복사하고, 모든 값이 0 이 되면 탐색 종료한 것
std::vector<int> path ;

void merge(int branch, std::vector<int> sub_path){
	if(path.empty()){
		path.insert(path.begin(), sub_path.begin(), sub_path.end());
		return ;
	}
	auto it = std::find(path.begin(), path.end(), branch);
	assert(it != path.end());
	path.insert(it + 1, sub_path.begin() + 1, sub_path.end());
}

std::vector<int> sub_circuit ;
int find_circuit(int target, int s){
	sub_circuit.push_back(s);
	for(int i = 1 ; i <= N ; i++){
		if(visited[s][i] >= 1){
			visited[s][i] -= 1;
			visited[i][s] -= 1;
			visited[0][s] -= 1;
			visited[0][i] -= 1;
			if(find_circuit(target, i)) return 1 ;
			if(i == target) return 1;
		}
	}
	return 0 ;
}

int find_next_start_node(){
	for(auto node : path){
		if(visited[0][node] != 0) return node ;
	}
	return -1 ;
}

void print_graph(int is_visited){
	for(int i = 0 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			if(is_visited){
				std::cout << visited[i][j] << " ";
			} else {
				std::cout << graph[i][j] << " ";
			}
		}
		std::cout << "\n";
	}	
}

int main(){
	
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);
	
	std::cin >> N ;
	if(N == 1){
		std::cout << 1 << "\n" ;
		return 0 ;
	}

	std::vector<int> odd_nodes ;
	for(int i = 1 ; i <= N ; i++){
		int num_edge = 0 ;
		for(int j = 1 ; j <= N ; j++){
			std::cin >> graph[i][j] ;
			visited[i][j] = graph[i][j];
			if(graph[i][j] >= 1) num_edge += graph[i][j];
		}
		graph[0][i] = num_edge ;
		visited[0][i] = num_edge ;
		if(num_edge % 2 == 1) odd_nodes.push_back(i);
	}

	if(odd_nodes.size() != 0 /*&& odd_nodes.size() != 2*/){
		std::cout << -1 << "\n";
		return 0 ;	
	} 

	/*
	if(odd_nodes.size() == 2){
		int a = odd_nodes[0] ; int b = odd_nodes[1] ;
		graph[a][b] += 1; graph[b][a] += 1;
		visited[a][b] += 1; visited[b][a] += 1;
		graph[0][a] += 1; graph[0][b] += 1;
		visited[0][a] += 1; visited[0][b] += 1;
	}*/

	int start_node = -1 ;
	for(int i = 1 ; i <= N ; i++){
		if(graph[0][i] > 0 ){
			start_node = i ;
			break;
		}
	}
	assert(start_node != -1);

	while(1){
		if(!path.empty()){
			start_node = find_next_start_node();
			//std::cout << start_node << "\n";
			if(start_node == -1) break ; 
		}
		find_circuit(start_node, start_node);
		merge(start_node, sub_circuit);
		sub_circuit.clear();
	}
	/*
	//print_graph(0);
	if(odd_nodes.size() == 2){
		for(int i = 0 ; i < path.size() - 1 ; i++){
			if((path[i] == odd_nodes[0] && path[i+1] == odd_nodes[1]) ||
				(path[i] == odd_nodes[1] && path[i+1] == odd_nodes[0])){
				for(int j = i + 1 ; j < path.size() - 1 ; j++){
					std::cout << path[j] << " ";
				}
				for(int j = 0 ;  j <= i ; j++){
					std::cout << path[j] << " ";
				}
				std::cout << "\n";
				return 0;
			}
		}
	}
	assert(odd_nodes.size() != 2);*/

	for(auto node : path){
		std::cout << node << " ";
	}
	std::cout << "\n";

	return 0;
}
