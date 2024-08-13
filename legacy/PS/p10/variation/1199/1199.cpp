#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int N ;
int graph[1001][1001];
int visited[1001] = {0};

bool input_init(){
	return 1 ;
}

std::vector<int> path ;
void find_next(int idx){

	path.push_back(idx);	
	visited[idx] = 1 ;

	if((int)path.size() == N){
		for(int i = 0 ; i < N ; i++){
			std::cout << path[i] << " ";
		}
		exit(0);
	}

	for(int i = 0 ; i < path.size() ; i++){
		std::cout << path[i] << " ";
	}
	std::cout << std::endl;	

	for(int i = 1 ; i <= N ; i++){
		int next = graph[idx][i];
		if(next == 1 && visited[i] == 0) find_next(i);
	}
}

void print_graph(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			std::cout << graph[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(){
	std::cin >> N ;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			int a; std::cin >> a ;
			graph[i][j] = a;
		}
	}

	if(!input_init()){
		std::cout << -1 << std::endl;
		return 0;
	}

	find_next(1);

	return 0;
}
