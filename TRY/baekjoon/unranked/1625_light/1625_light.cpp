#include <iostream>

int init_lights[256][256];
int last_lights[256][256];

int R, C ;

int main(){
	std::cin >> R >> C ;

	for(int i = 0 ; i < R ; i++)
		for(int j = 0 ; j < C ; j++)
			std::cin >> init_lights[i][j] ;

	for(int i = 0 ; i < R ; i++)
		for(int j = 0 ; j < C ; j++)
			std::cin >> last_lights[i][j] ;



	return 0;
}