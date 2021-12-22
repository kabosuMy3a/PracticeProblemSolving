#include <iostream>
#include <cstring>
#include <cctype>

std::string s ;
std::string new_s ; 


int main(){
	std::cin >> s ;

	int isJava = 0 ;
	int isCPP = 0 ;
	int next_should_be_upper = 0 ;
	int isFirst = 1 ;

	for(auto c : s){
		if(c >= 'A' && c <= 'Z') {
			if(isFirst ) {
				std::cout << "Error!" << std::endl;
				return 0 ;
			}
			isJava = 1 ;
			if(isCPP){
				std::cout << "Error!" << std::endl;
				return 0;
			}
			new_s += '_';
			new_s += c + 32 ;
			continue;
		} 
		else if(c == '_'){
			if(isFirst || next_should_be_upper) {
				std::cout << "Error!" << std::endl;
				return 0 ;
			}
			isCPP = 1 ;
			if(isJava){
				std::cout << "Error!" << std::endl;
				return 0;
			}
			next_should_be_upper = 1 ;
			continue ;

		} else if(c >= 'a' && c <= 'z'){

			if(next_should_be_upper){
				if(c >= 'a' && c <= 'z'){
					new_s += c - 32 ;
				}
				next_should_be_upper = 0 ;
				continue;
			} 

			new_s += c ;
		} else {
			std::cout << "Error!" << std::endl;
			return 0 ;
		}
		if(isFirst) isFirst = 0 ;
	}
	if(next_should_be_upper == 1){
		std::cout << "Error!" << std::endl;
		return 0;
  	}

	std::cout << new_s << std::endl;
	return 0 ;
	
}