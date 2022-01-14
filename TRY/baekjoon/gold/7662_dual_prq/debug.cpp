#include <iostream>
#include <unordered_map>
#include <queue>

std::unordered_map<int, int> storage ;

int main(){
	std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0); std::cout.tie(0x0);
	int T ; std::cin >> T ;
	for(int t = 0 ; t < T ; t++){
		storage.clear();
		std::priority_queue<int> max_pq ;
		std::priority_queue<int> min_pq ; //push & top (item * -1) 
		int N ; std::cin >> N;
		for(int i = 0 ; i < N + 2; i++){
			char opt ; int  opr ; 
			if(i == N){
				opt = 'D' ; opr = 1 ; 
			} 
			else if(i == N+1){
				opt = 'D' ; opr = -1;
			} else {
				std::cin >> opt ;
				std::cin >> opr ;
			}

			if(opt == 'I'){
				max_pq.push(opr);
				min_pq.push(opr * -1);
				auto iter = storage.find(opr);
				if(iter != storage.end()){
					storage[opr] += 1;
				} else {
					storage.insert({opr,1});
				}
			} else {
				if(opr == -1){
					while(true){
						if(min_pq.empty()) break ;
						int min_val = min_pq.top() * -1 ;
						min_pq.pop();
						auto iter = storage.find(min_val);
						if(iter == storage.end()) continue ;
						else {
							if(i == N+1) std::cout << min_val << "\n";
							else {
								int a = storage[min_val] ;
								if(a == 1) storage.erase(min_val);
								else storage[min_val] -= 1;
							}
							break; 
						}
					}

				} else {
					while(true){
						if(max_pq.empty()){
							if(i == N) std::cout << "EMPTY\n" ;
							break; 
						}
						int max_val = max_pq.top();
						max_pq.pop();
						auto iter = storage.find(max_val);
						if(iter == storage.end()) continue ; 
						else {
							if(i == N) std::cout << max_val << " ";
							else {
								int a = storage[max_val] ;
								if(a == 1) storage.erase(max_val);
								else storage[max_val] -= 1;
							}
							break; 
						}
					}
				}

			}
		}

		/*		
		for(auto s : storage){
			std::cout <<"("<< s.first << ", " << s.second << ") " ;
		}
		std::cout << "\n";*/

	}
	return 0; 
}