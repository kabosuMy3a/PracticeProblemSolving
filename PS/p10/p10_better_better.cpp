#include <iostream>
#include <algorithm>
#include <vector>

int N ;
std::string words[1000];

std::vector<int> next_word_graph[1000] ;
int same_first_char_idx[27] ;

int num_next_available[1000] ;

bool input_init(int * start_point){
	int num_char[30] = {0} ; 
	int first_char[26] = {0} ;
	for(int i = 0 ; i < N ; i++){
		char f = words[i][0] ;
		char r = words[i][words[i].size()-1] ;
		num_char[f - 'a'] += 1;	
		num_char[r - 'a'] -= 1;	
		first_char[f - 'a'] += 1; 
	}

	same_first_char_idx[0] = 0 ;
	for(int i = 1 ; i <= 26 ; i++){
		same_first_char_idx[i] = first_char[i-1] + same_first_char_idx[i-1] ;
	}

	int valid[3] = {0} ;
	for(int i = 0 ; i < 30 ; i++){
		int cur = num_char[i] + 1 ;
		if(cur > 2 || cur < 0) return false ;
		if(cur == 2){
			*start_point = same_first_char_idx[i + 1] - 1 ;
		}
		valid[cur] += 1;
	}

	if(valid[0] == 1 && valid[1] == 28 && valid[2] == 1)
		return true ;
	if(valid[1] == 30)
		return true ;

	return false ;  
}


void make_next_word_graph(){
	for(int i = 0 ; i < N ; i++){
		char r = words[i][words[i].size()-1];
		int st = same_first_char_idx[r - 'a' ];
		int en = same_first_char_idx[r - 'a' + 1];
		for( ; st < en ; st++)
			next_word_graph[i].push_back(st);
	}
}

std::vector<int> path ;
int find_next(int idx){
	if(num_next_available[idx] != -1 && ((int)path.size() + 1 + num_next_available[idx] != N)){ 
		return num_next_available[idx] ;
	}

	for(int i = 0 ; i < (int)path.size() ; i++){
		if(idx == path[i]){ 
			return num_next_available[idx];
		}
	}
	
	path.push_back(idx);
	
	if((int)path.size() == N){
		for(int i = 0 ; i < N ; i++){
			std::cout << words[path[i]] << std::endl;
		}
		exit(0);
	}

	int max_next_available = 0 ;
	for(int next_word : next_word_graph[idx]){
		if(next_word == idx) continue;
		int next_available = find_next(next_word) + 1 ;
		if(max_next_available < next_available) max_next_available = next_available ;
	}
	
	path.pop_back();
	num_next_available[idx] = max_next_available ;
	return max_next_available ;
}

int main(){
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		std::cin >> words[i] ;
		num_next_available[i] = -1 ;
	}

	std::sort(words, words+ N);
	int start_point = 0 ;
	if(!input_init(&start_point)){
		std::cout << 0 << std::endl;
		return 0;
	}
	make_next_word_graph();

	if(start_point != 0){
		find_next(start_point); 
	} else {
		for(int i = 0 ; i < N ; i++){
			find_next(i);
		}
	}
	
	return 0;
}
