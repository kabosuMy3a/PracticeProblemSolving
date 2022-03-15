#include <cstring>
#include <iostream>

int check(std::string & str, int s, int e, int state){
	if(s >= e || state >= 2) return state ;

	if(str[s] == str[e]){
		return check(str, s + 1, e -1 , state);
	} else {
			if(s + 1 == e){
				return state + 1 ;
			} else {
				int a = 2 ;
				if(str[s + 1] == str[e]){
					int b = check(str, s + 2, e - 1, state + 1) ;
					if(a > b) a = b ;
				}
				if(str[s] == str[e - 1]){
					int b = check(str, s + 1, e - 2, state + 1);
					if(a > b) a = b ;
				}
				return a ;
			}
	} 
}

int main(){
	int T ; std::cin >> T ;
	for(int t = 0 ; t < T ; t++){
		std::string str ; std::cin >> str ;
		int e = str.length() - 1 ; int s = 0 ;
		int state = check(str, s, e, 0);
		std::cout << state << "\n";
	}

	return 0 ; 
}