#include <iostream>
#include <string>

short num_cur_match[2][7000] = {0,};

int main(){
	short max_match = 0 ;
	std::string s1, s2 ; std::cin >> s1 >>  s2 ;
	int R = (int) s1.size(); int C = (int) s2.size();

	for(int i = 0 ; i < R ; i++){
		int prev, cur ;
		if(i % 2 == 0){
			prev = 1 ;
			cur = 0 ;
		} else {
			prev = 0 ;
			cur = 1 ;
		}

		for(int j = 0 ; j < C ; j++){
			if(s1[i] != s2[j]){
				if(i != 0 && j != 0){
					if(num_cur_match[prev][j] < num_cur_match[cur][j-1]){
						num_cur_match[cur][j] = num_cur_match[cur][j-1];
					} else {
						num_cur_match[cur][j] = num_cur_match[prev][j];
					}
				} else if(i != 0){
					num_cur_match[cur][j] = num_cur_match[prev][j];
				} else if(j != 0){
					num_cur_match[cur][j] = num_cur_match[cur][j-1];
				}
			} else /* same */{
				num_cur_match[cur][j] = 1 ;
				if(i != 0 && j != 0){
					num_cur_match[cur][j] += num_cur_match[prev][j-1];
				}
			}
			if(max_match < num_cur_match[cur][j]) max_match = num_cur_match[cur][j] ;
		}

		/*
		for(int j = 0 ; j < C ; j++){
			std::cout << num_cur_match[prev][j] << " ";
		}
		std::cout << "\n";

		for(int j = 0 ; j < C ; j++){
			std::cout << num_cur_match[cur][j] << " ";
		}
		std::cout << "\n\n";*/
	}

	std::cout << max_match << "\n";
	return 0; 
}