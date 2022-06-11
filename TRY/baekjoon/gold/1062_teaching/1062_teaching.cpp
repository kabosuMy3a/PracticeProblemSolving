#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


std::vector<char> will_learn_char ;
int arr[21] ;
std::vector<std::string> words ;


int main(){
	
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);

	int N, K ; std::cin >> N >> K ; 
	K = K - 5 ;

	if(K < 0){
		std::cout << 0 << "\n" ;
		return 0 ;
	}

	for(int i = 0 ; i < N ; i++) {
		std::string s ; std::cin >> s ;
		words.push_back(s);
	}

	for(int i = 0 ; i < 26 ; i++){
		char c = i + 97 ;
		if(c == 'a' || c == 'n' || c == 't' || c  == 'i' || c == 'c') continue ;
		will_learn_char.push_back(c);
	}

	for(int i = 0 ; i < 21 - K ; i++) arr[i] = 0 ;
	for(int i = 21 - K  ; i < 21 ; i++) arr[i] = 1 ;


	int ans = 0 ;
	do {
		int cur_set[128] = {0,};
		for(int i = 0 ; i < 21 ; i++){
			if(arr[i] == 1){
				int idx = will_learn_char[i] ;
				cur_set[idx] = 1 ;
			}
		}

		int cur_known_word_num = 0 ;
		for(auto s : words){
			int flag = 1 ;
			for(auto c : s){
				if(c == 'a' || c == 'n' || c == 't' || c  == 'i' || c == 'c') continue ;
				int idx = (int)c ;
				if(cur_set[idx] == 0){
					flag = 0 ;
					break; 
				}
			}

			if(flag == 1){
				cur_known_word_num++ ;
			}
		}

		if(ans < cur_known_word_num) ans = cur_known_word_num ;

	} while(std::next_permutation(arr, arr+21)) ; 

	std::cout << ans << "\n" ;
	return 0;
} 