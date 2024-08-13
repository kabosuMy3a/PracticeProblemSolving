#include <iostream>
#include <map>
#include <cstring>

std::map<std::string, int> people ;

int main(){

	int N ; int  M;
	std::cin >> N >> M ;
	int num = 0 ;

	for(int i = 0 ; i < N + M ; i++){
		std::string s ; std::cin >> s;
		auto it = people.find(s);
		if(it != people.end()){
			num++;
			it->second = 2 ;	
		} else {
 			people.insert({s,1});
 		}
	}

	std::cout << num << "\n";
	for(auto it = people.begin() ; it != people.end() ; it++){
		if(it->second == 2) std::cout << it->first << "\n";
	}

	return 0; 
}