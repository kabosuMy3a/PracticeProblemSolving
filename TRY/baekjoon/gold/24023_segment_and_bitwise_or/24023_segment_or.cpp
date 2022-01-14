#include <iostream>

int main(){
	
	int N ; std::cin >> N ;
	int origin ; std::cin >> origin ;
	int target = origin ;
	int cur ; int s = 1 ;
	for(int i = 1 ; i <= N ; i++){
		std::cin >> cur ;
		if((origin | cur) <= origin){
			target -= (cur & target) ;
			if(target == 0){
				std::cout << s << " ";
				std::cout << i << "\n";
				return 0 ;
			}
		} else {
			s += 1 ;
			target = origin ;
		}
	}
	std::cout << -1 << "\n" ;


	return 0 ;
}