#include <iostream>
#include <algorithm>

int N ;
std::string words[1000];

bool is_valid_input(){
	int num_char[30] = {0} ;
	for(int i = 0 ; i < N ; i++){
		char f = words[i][0] ;
		char r = words[i][words[i].size()-1] ;
		num_char[f - 'a'] += 1;
		num_char[r - 'a'] -= 1;
	}

	int valid[3] = {0} ;
	for(int i = 0 ; i < 30 ; i++){
		int cur = num_char[i] + 1 ;
		if(cur > 2 || cur < 0) return false ;
		valid[cur] += 1;
	}
	if(valid[0] == 1 && valid[1] == 28 && valid[2] == 1)
		return true ;
	if(valid[1] == 30)
		return true ;

	return false ;  
}

int main(){
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++)
		std::cin >> words[i] ;
	if(!is_valid_input()){
		std::cout << 0 << std::endl;
		return 0;
	}

	std::sort(words, words+ N);

	for(int i = 0 ; i < N ;i++){
		std::cout << words[i] << std::endl;
	}	

	return 0;
}
