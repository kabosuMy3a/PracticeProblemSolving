#include <iostream>
#include <string>

int main(){
	
	int N ; std::cin >> N ; int ans = 0 ;
	for(int i = 0 ; i < N ; i++){
		int alpha[50] = {0,} ;
		std::string s ; std::cin >> s ;
		int prev = -1 ; int flag = 1 ;
		for(auto c : s){
			int cur = c - 'a';
			if(prev == -1){
				alpha[cur] = 1 ;
			} else if(prev == cur){
				alpha[cur] += 1 ;
			} else {
				if(alpha[cur] != 0){
					flag = 0 ;
					break ; 
				} else {
					alpha[cur] += 1 ;
				}
			}
			prev = cur 	;
		}
		if(flag) ans+= 1;
	}

	std::cout << ans <<"\n";
	return 0; 
}