#include <iostream>
#include <cstring>

int fib[41] ;
int num_zero[41] ;
int num_one[41] ;

int main(){
	std::ios
	int T ; std::cin >> T ;
	fib[0] = 0 ; num_zero[0]= 1; num_one[0] = 0 ;
	fib[1] = 1 ; num_zero[1] = 0 ; num_one[1] = 1 ;
	for(int i = 2 ; i <= 40 ; i++){
		fib[i] = fib[i-1] + fib[i-2] ;
		num_zero[i] = num_zero[i-1] + num_zero[i-2] ;
		num_one[i] = num_one[i-1] + num_one[i-2] ;
	}

	for(int t = 0 ; t < T ; t++){
		int N ; std::cin >> N ;
		std::cout << num_zero[N] << " " << num_one[N] << "\n";
	}


	return 0 ;
}