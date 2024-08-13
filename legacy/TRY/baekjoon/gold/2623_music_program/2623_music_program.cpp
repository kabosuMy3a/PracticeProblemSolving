#include <iostream>
#include <vector>
#include <queue>

int num_singers_before[1001] = {0,};
std::vector<int> singer_graph[1001]; 

int main(){

	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);

	int N, M ; std::cin >> N >> M ;
	for(int m = 0 ; m < M ; m++){
		int orders ; std::cin >> orders ;
		int prev = -1 ;
		for(int order = 0 ; order < orders ; order++){
			int cur ; std::cin >> cur ;
			if(prev != -1){
				num_singers_before[cur] += 1 ;
				singer_graph[prev].push_back(cur);
			}
			prev = cur ;
		}
	}

	std::queue<int> election_queue ;
	std::queue<int> answer_queue ;

	for(int i = 1 ; i <= N ; i++){
		if(num_singers_before[i] == 0) election_queue.push(i);
	}

	while(!election_queue.empty()){
		int cur = election_queue.front(); 
		election_queue.pop();
		answer_queue.push(cur);

		for(auto next : singer_graph[cur]){
			num_singers_before[next] -= 1 ;
			if(num_singers_before[next] == 0) election_queue.push(next);
		}
	}

	if(answer_queue.size() == N){
		while(!answer_queue.empty()){
			std::cout << answer_queue.front() << "\n";
			answer_queue.pop();
		}
	} else {
		std::cout << 0 << "\n";
	}

	return 0 ;
}