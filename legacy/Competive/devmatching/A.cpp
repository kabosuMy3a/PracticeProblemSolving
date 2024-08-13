#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>


int main(){
	
	std::string s =  "2019/01/01 5000" ;
	std::string yy = s.substr(0, 4);
	std::string mm = s.substr(5, 2);
	std::string dd = s.substr(8, 2);
	std::string price = s.substr(11);

	std::cout << std::stoi(dd);

	return 0 ;
}