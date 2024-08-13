#include <iostream>
#include <utility>
#include <cstdlib>

int num_cops ;
std::pair<long long, long long> cops[500000];
std::pair<long long, long long> theif ; 


int main(){

	std::cin >> num_cops ;
	for(int i = 0 ; i <= num_cops ; i++){
		long long a, b ;
		std::cin >> a >> b ; 
		if(i == num_cops) theif = std::make_pair(a, b);
		cops[i] = std::make_pair(a, b);
	}

	bool cn = 0; bool cs = 0; bool cw = 0; bool ce = 0;
	for(auto cop : cops){
		long long dist_y = abs(cop.second - theif.second) ;
		long long dist_x = abs(cop.first - theif.first) ;
		if(cop.second > theif.second){
			//can catch north
			if(dist_x <= dist_y) cn = 1 ;
		}

		if(cop.second < theif.second){
			//can catch south
			if(dist_x <= dist_y) cs = 1 ;

		}

		if(cop.first > theif.first){
			//can catch east			
			if(dist_y <= dist_x) ce = 1 ;
		}

		if(cop.first < theif.first){
			//can catch west
			if(dist_y <= dist_x) cw = 1; 
		}
	}

	if(cn && cs && cw && ce) std::cout <<"NO"<< std::endl ;
	else std::cout << "YES" << std::endl;

	return 0;
}