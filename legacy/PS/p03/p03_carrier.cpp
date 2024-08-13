#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

int main(){

	int m ; 
	std::cin >> m ;

	std::vector<int> sorted_list = std::vector<int>();

	int num_carrier = 0 ;
	int w ;
	while(std::cin >> w){
		sorted_list.push_back(w);
	}

	std::sort(sorted_list.begin(), sorted_list.end(), std::greater<int>());
	std::deque<int> sorted_deq(sorted_list.size());
	std::copy(sorted_list.begin(), sorted_list.end(), sorted_deq.begin());

	while(sorted_deq.size() != 0){
		if(sorted_deq.size() == 1){
			num_carrier += 1;
			break; 
		}

		int f = sorted_deq.front();
		int r = sorted_deq.back();

		if(f+r <= m){
			sorted_deq.pop_back();
		}
		sorted_deq.pop_front();
		num_carrier += 1;

	}

	std::cout << num_carrier << std::endl ;

	return 0 ;
}