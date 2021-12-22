#include <iostream>
#include <algorithm>
#include <queue>

std::priority_queue<int> left_max_pq ;
std::priority_queue<int, std::vector<int>, std::greater<int>> right_min_pq ;
int pivot ;
int cur_num = 0;

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0); std::cout.tie(0x0);
	int N ; std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int a ; std::cin >> a ;
		if(cur_num == 0) pivot = a;
		
		else if((cur_num % 2 == 1)){
			if(pivot <= a){
				right_min_pq.push(a); 
			} else {
				int next_pivot = a ;
				if(!left_max_pq.empty()){
					int left_max = left_max_pq.top();
					if(left_max > a){
						left_max_pq.pop();
						left_max_pq.push(a);
						next_pivot = left_max ;
					}
				}
				right_min_pq.push(pivot);
				pivot = next_pivot ;
			}

		} else {
			if(a <= pivot){
				left_max_pq.push(a);
			} else {
				int next_pivot = a ;
				if(!right_min_pq.empty()){
					int right_min = right_min_pq.top();
					if(right_min < a){
						right_min_pq.pop();
						right_min_pq.push(a);
						next_pivot = right_min ;
					}
				}
				left_max_pq.push(pivot);
				pivot = next_pivot ;
			}
		}

		std::cout << pivot << "\n" ;
		cur_num += 1;
	}

	return 0 ;
}