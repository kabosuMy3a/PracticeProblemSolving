#include <iostream>
#include <string>

short num_cur_match[1000][1000];
short origin_match[1000][1000];

int main(){
	short max_match = 0 ;
	std::string s1, s2 ; std::cin >> s1 >>  s2 ;
	int R = (int) s1.size(); int C = (int) s2.size();

	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if(s1[i] == s2[j]){
				num_cur_match[i][j] = 1 ;
				origin_match[i][j] = 1 ;
			}
			else {
				num_cur_match[i][j] = 0;
				origin_match[i][j] = 0 ;
			}
		}
	}

	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			if(origin_match[i][j] == 0){
				if(i != 0 && j != 0){
					if(num_cur_match[i-1][j] < num_cur_match[i][j-1]){
						num_cur_match[i][j] += num_cur_match[i][j-1];
					} else {
						num_cur_match[i][j] += num_cur_match[i-1][j];
					}
				} else if(i != 0){
					num_cur_match[i][j] += num_cur_match[i-1][j];
				} else if(j != 0){
					num_cur_match[i][j] += num_cur_match[i][j-1];
				}
			} else {
				if(i != 0 && j != 0){
					num_cur_match[i][j] += num_cur_match[i-1][j-1];
				}
			}

			if(max_match < num_cur_match[i][j]) max_match = num_cur_match[i][j] ;
		}
	}

	/*
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			std::cout << num_cur_match[i][j] << " ";
		}
		std::cout << "\n";
	}*/

	std::cout << max_match << "\n";
	return 0; 
}