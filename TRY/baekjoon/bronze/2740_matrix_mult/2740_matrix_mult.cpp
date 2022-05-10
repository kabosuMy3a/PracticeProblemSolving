#include <iostream>

int A[100][100] ;
int B[100][100] ;
int C[100][100] ;

int main(){

	int N, M, K ; std::cin >> N >> M ;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			std::cin >> A[i][j] ;
		}
	}

	std::cin >> M >> K ;
	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < K ; j++){
			std::cin >> B[i][j] ;
		}
	}

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < K ; j++){
			C[i][j] = 0 ;
			for(int k = 0 ; k < M ; k++){
				C[i][j] += A[i][k] * B[k][j] ; 
			}
		}
	}

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < K ; j++){
			std::cout << C[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}