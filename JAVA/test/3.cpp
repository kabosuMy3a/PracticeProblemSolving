#include <iostream>
#include <vector>

int passenger[6];
std::vector<int> train[6];

int max_passenger = 0 ;
int max_passenger_idx = 0 ; 

void dfs(int cur, int prev, int cur_passenger){
	cur_passenger += passenger[cur];
	if(cur_passenger >= max_passenger){
		max_passenger = cur_passenger ;
		max_passenger_idx = cur ;
	}

	for(auto next : train[cur]){
		if(next == prev) continue ;
		dfs(next, cur, cur_passenger);
	}
}

int main(){

	int N ;
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++) std::cin >> passenger[i] ;
	for(int i = 0 ; i < N ; i++){
		int a, b ; std::cin >> a >> b;
		train[a-1].push_back(b-1);
		train[b-1].push_back(a-1);
	}

	dfs(0, -1, 0);
	std::cout << max_passenger_idx + 1<< " " << max_passenger << "\n";


	return 0 ;
}