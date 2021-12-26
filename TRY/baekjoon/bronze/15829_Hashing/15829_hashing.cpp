#include <iostream>
#include <cmath>
#include <cstring>

std::string s ;

int main(){
	
	long long r = 1 ;
	int N ; std::cin >> N;
	std::cin >> s ;
	long long sum = 0 ;
	for(auto c : s){
		sum += (((c-'a' + 1) * r) % 1234567891) ;
		r *= 31 ;
	}
	sum = sum % 1234567891 ;
	std::cout << sum << std::endl;
	return 0 ;
}