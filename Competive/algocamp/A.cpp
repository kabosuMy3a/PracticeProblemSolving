#include <iostream>
#include <cstring>

int main(){
	int T ; std::cin >> T ;
	int T_ans_max = 0 ;
	for(int t = 0 ; t < T ; t++){
		int ans = 0 ;
		std::string s ; std::cin >> s;
		for(int i = 0 ; i < s.length() ; i++){
			std::string f = s.substr(i, 3);
			std::string w = s.substr(i, 5);
			if(f == "for"){
				ans++ ;
				i += 2 ;
			} else if(w == "while"){
				ans++ ;
				i += 4 ;
			}
		}
		if(ans > T_ans_max) T_ans_max = ans ;
	}
	std::cout << T_ans_max << "\n";

	return 0;
}