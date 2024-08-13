#include <iostream>
#include <algorithm>

int printers[3][4] ;

int main(){

	int T ; std::cin >> T ;
	for(int t = 1 ; t <= T ; t++){
		for(int i = 0 ; i < 3 ; i++){
			for(int j = 0 ; j < 4 ; j++){
				std::cin >> printers[i][j];
			}
		}

		int C = 0 ; int Y = 0 ; int M = 0; int K = 0 ;
		int c = std::min(printers[0][0], std::min(printers[1][0], printers[2][0]));
		int y = std::min(printers[0][1], std::min(printers[1][1], printers[2][1]));
		int m = std::min(printers[0][2], std::min(printers[1][2], printers[2][2]));
		int k = std::min(printers[0][3], std::min(printers[1][3], printers[2][3]));

		int over_flag = 0 ;
		C += c ; 
		if(C >= 1'000'000){
			over_flag = 1;
			C = 1'000'000 ;
		}

		if(over_flag){
			Y = 0 ;
		} else {
			Y += y ;
			if(C + Y >= 1'000'000){
				over_flag = 1 ;
				Y = 1'000'000 - C ;
			}
		}

		if(over_flag){
			M = 0 ;
		} else {
			M += m ;
			if(C + Y + M >= 1'000'000){
				over_flag = 1 ;
				M = 1'000'000 - C - Y ;
			}
		}

		if(over_flag){
			K = 0 ;
		} else {
			K += k ;
			if(C + Y + M + K >= 1'000'000){
				over_flag = 1 ;
				K = 1'000'000 - C - Y - M ;
			}
		}

		std::cout << "Case #" << t << ": " ;
		if(over_flag){
			std::cout << C << " " << Y << " " << M << " " << K << "\n";
		} else {
			std::cout << "IMPOSSIBLE\n" ;
		}

	}


	return 0 ;
}