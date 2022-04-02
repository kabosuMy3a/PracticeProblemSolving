#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

std::string words[20] ;
std::vector<int> permutator;
int N ; int num_words ;

std::vector<std::string> path ;
int used[20] = {0,} ;


int check(int next){
	int target_idx = path.size()  ;
	std::string next_word = words[next] ;
	for(int i = 0 ; i < (int)path.size() ; i++){
		std::string taget_word = path[i] ;
		if(taget_word[target_idx] != next_word[i]) return 0 ;
	}

	return 1 ;
}

void dfs(int cur){
	path.push_back(words[cur]);
	used[cur] = 1;
	if(path.size() == N){
		for(auto s : path){
			std::cout << s << "\n";
		} 
		exit(0);
	}

	for(int next = 0 ; next < num_words ; next++){
		if(used[next]) continue ;
		if(cur == next) continue ;
		if(check(next)) dfs(next) ;	
	}

	path.pop_back(); 
	used[cur] = 0 ;
}

int main(){
	
	std::cin >> N >> num_words ;
	for(int i = 0 ; i < num_words ; i++){
		std::cin >> words[i] ;
	}

	std::sort(words, words + num_words);

	for(int i = 0 ; i < num_words ; i++){
		dfs(i);
	}

	std::cout << "NONE" << "\n";
	/* 틀린 방법 // 백트래킹이 아님
	std::vector<std::string> cur ;
	int used[20] ;
	for(int i = 0 ; i < num_words ; i++){
		cur.clear();
		for(int j = 0 ; j < num_words ; j++) used[j] = 0 ;
		
		cur.push_back(words[i]) ; used[i] = 1 ;
		while(1){
			int flag = 0 ;
			for(int j = 0 ; j < num_words ; j++){

			}
			if(!flag) break ; 
			if()
		}

	}
	*/

	/* 틀린 방법 // 사전순으로 빠른 답 출력 못함
	for(int i = 0 ; i <num_words ;i++){
		std::cout << words[i] << "\n";
	}
	
	for(int i = 0 ; i < N ; i++) permutator.push_back(1);
	for(int i = 0 ; i < num_words - N ; i++) permutator.push_back(0);

	std::vector<std::string> cur_words ;
	do{
		cur_words.clear(); int idx = 0 ;
		for(auto a : permutator){
			if(a == 1) cur_words.push_back(words[idx]);
			idx++;
		}

		do{

		}while(std::next_permutation(cur_words.begin(), cur_words.end()));

	} while(std::prev_permutation(permutator.begin(), permutator.end())) ;

	std::cout << "NONE" ;
	return 0 ;*/
}