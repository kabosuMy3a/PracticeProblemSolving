#include <iostream>
#include <cassert>

int T, cur_joker ;

int main(){
	std::ios_base::sync_with_stdio(0x0);

	std::cin >> T ; cur_joker = 1 ;
	for(int t = 0 ; t < T ; t++){
		int shuffle[27]; int idx = 0;
		int sum = 0 ; int next_joker = 0 ;
		while(true){
			std::cin >> shuffle[idx]; 
			sum += shuffle[idx]; idx++ ;
			if(sum == 27) break;
		}
		
		if(cur_joker >= 1 && cur_joker <= 13){
			next_joker += shuffle[0]; int left_idx = 0 ;
			for(int i = 1 ; i < idx ; i += 2){
				left_idx += shuffle[i];
				if(left_idx >= cur_joker){
					next_joker += cur_joker ;
					break;
				} else {
					if(i+1 != idx) next_joker += shuffle[i+1] ;
				}
			}
		} else {
			cur_joker -= 13 ; int right_idx = 0;
			for(int i = 0 ; i < idx ; i += 2){
				right_idx += shuffle[i];
				if(right_idx >= cur_joker){
					next_joker += cur_joker ;
					break;
				} else {
					if(i+1 != idx) next_joker += shuffle[i+1];
				}
			}
		}
		cur_joker = next_joker ;
	}
	std::cout << cur_joker << "\n";

	return 0;
}