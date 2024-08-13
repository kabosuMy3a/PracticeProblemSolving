#include <iostream>
#include <algorithm>

long long v_sum = 0 ;
long long v_xor = 0 ;

int main(){

	int N ; std::cin >> N ;

	for(int i = 0 ; i <  N ; i++){
		int q ; std::cin >> q ;
		if(q == 1) {
			int obj ; std::cin>> obj ;
			v_sum += obj ;
			v_xor ^= obj ;
		}
		if(q == 2){
			int obj ; std::cin>> obj ;
			v_sum -= obj ;
			v_xor ^= obj ;
		}

		if(q == 3) std::cout << v_sum << std::endl;
		if(q == 4) std::cout << v_xor << std::endl;	
	}

	return 0 ;
}