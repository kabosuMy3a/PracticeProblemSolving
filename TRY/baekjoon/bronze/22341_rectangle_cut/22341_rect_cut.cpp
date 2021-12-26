#include <iostream>

int N ; int C ;


int main(){

	std::cin >> N >> C;
	int cur_x = N ; int cur_y = N;
	int cx, cy ;

	for(int i = 0 ; i < C ; i++){
		std::cin >> cx >> cy ;
		if(cx >= cur_x) continue ;
		if(cy >= cur_y) continue ;

		if(cx * cur_y >= cy * cur_x){
			cur_x = cx ;
		} else {
			cur_y = cy ;
		}
	}

	std::cout << cur_x * cur_y << std::endl;
	return 0 ;
}