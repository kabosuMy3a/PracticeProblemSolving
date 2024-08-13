#include <iostream>
#include <deque>
#include <cstring>

int T, N ;
std::deque<int> nums ;

int main(){

	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0); std::cout.tie(0x0);
	std::cin >> T ;

	for(int t = 0 ; t < T ; t++){
		int isReversed = 0 ;
		std::string command ;
		std::cin >> command ;
		std::cin >> N ;
		std::string arr ; std::cin >> arr ;
		std::string cur_num = "";

		for(auto c : arr){
			if(c == '['){
			} else if(c == ',' || c== ']'){
				if(N == 0) continue ;
				nums.push_back(std::stoi(cur_num)); 
				cur_num = "";
			} else{
				cur_num += c ;
 			}
		}

		int is_error = 0 ;
		for(auto c : command){
			if(c == 'R') isReversed ^= 1 ;
			else{
				if(nums.size() == 0){
					std::cout << "error" <<"\n";
					is_error = 1 ;
					continue ;
				}
				if(isReversed){
					nums.pop_back();
				} else {
					nums.pop_front();
				}
			}
		}
		if(is_error) continue ;

		if(nums.size() <= 1){
			std::cout <<"[" ;
			for(auto num : nums) std::cout << num ;
			std::cout << "]\n";
			nums.clear();
			continue ; 
		}

		if(isReversed){
			for(auto it = nums.end() - 1 ; it >= nums.begin() ; it--){
				if(it == nums.end() -1) std::cout << "[" << *it << "," ;
				else if(it == nums.begin()) std::cout << *it << "]\n";
				else std::cout << *it <<",";
			}			

		} else {
			for(auto it = nums.begin() ; it != nums.end() ; it++){
				if(it == nums.begin()) std::cout << "[" << *it << "," ;
				else if(it == nums.end()-1) std::cout << *it << "]\n";
				else std::cout << *it <<",";
			}
		}

		nums.clear();
	}


	return 0 ;
}
