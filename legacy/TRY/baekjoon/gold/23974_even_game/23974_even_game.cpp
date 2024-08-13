#include <iostream>

int YG[2][10000001] ;
int HS[2][10000001] ;

int N ; int K ;

#define L 0 
#define W 1

int main(){

	std::cin >> K >> N ;

	YG[0][1] = L ; YG[1][1] = W ;
	HS[0][1] = L ; HS[1][1] = W ;
	for(int i = 2 ; i <= 4 ; i++){
		YG[0][i] = W ; YG[1][i] = W ;
		HS[0][i] = W ; HS[1][i] = W ;
	}

	for(int i = 5 ; i <= N ; i++){
		YG[0][i] = L ;
		for(int j  = 1 ; j <= 4 ; j++){
			int cur = j % 2  ;
			if(HS[cur][i-j] == L) YG[0][i] = W ;
		}

		YG[1][i] = L ;
		for(int j  = 1 ; j <= 4 ; j++){
			int cur = (1 + j) % 2  ;
			if(HS[cur][i-j] == L) YG[1][i] = W ;
		}

		HS[0][i] = L ;
		for(int j  = 1 ; j <= 4 ; j++){
			int cur = 0  ;
			if(YG[cur][i-j] == L) HS[0][i] = W ;
		}

		HS[1][i] = L ;
		for(int j  = 1 ; j <= 4 ; j++){
			int cur = 1  ;
			if(YG[cur][i-j] == L) HS[1][i] = W ;
		}
	}

	/*
	for(int j = 1 ; j <= N ; j++){
		for(int i = 0 ; i < 4 ; i++){
			if(i == 0){
				std::cout << j << "  ";
				std::cout << i << "|";
				if(YG[0][j] == L)
					std::cout << "L|";
				else
					std::cout << "W|";
			}
			if(i == 1){
				std::cout << i << "|";
				if(YG[1][j] == L)
					std::cout << "L|     ";
				else
					std::cout << "W|     ";
			}
			if(i == 2){
				std::cout << 0 << "|";
				if(HS[0][j] == L)
					std::cout << "L|";
				else
					std::cout << "W|";
			}

			if(i == 3){
				std::cout << 1 << "|";
				if(HS[1][j] == L)
					std::cout << "L|";
				else
					std::cout << "W|";
				std::cout << "\n";
			}
		}
	}*/

	if(YG[K][N] == L) std::cout << "HS\n" ;
	else std::cout << "YG\n" ;

	return 0 ; 
}