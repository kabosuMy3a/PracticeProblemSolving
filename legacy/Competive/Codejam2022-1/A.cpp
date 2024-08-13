#include <iostream>
#include <string>
#include <vector>

int main(){

	int T ; std::cin >> T ;	

	for(int t = 1 ; t <= T ; t++){
		int R, C; std::cin >> R >> C ;
		std::vector<std::string> ans ;
		for(int i = 0 ; i < R + R + 1 ; i++) ans.push_back("");
		for(int i = 0 ; i < R + R + 1 ; i++){
			if(i == 0 || i == 1) ans[i] += "..";
			else if(i % 2 == 0) ans[i] += "+-";
			else ans[i] += "|.";

			for(int j = 0 ; j < C - 1 ; j++){
				if(i % 2 == 0) ans[i] += "+-";
				else ans[i] += "|.";
			}

			if(i%2 == 0) ans[i] += "+";
			else ans[i] += "|";  
		}

		std::cout << "Case #" << t << ":\n" ;
		for(auto s : ans){
			std::cout << s << "\n";
		}
	}

	return 0 ;
}