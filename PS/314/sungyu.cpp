#include <iostream>

void solve2(int n){
	long long result[51]; 
	result[0] = 1;
	result[1] = 1;
	result[2] = 1;


	for(int i = 3; i <= 50 ; i++){
		int a = i-1 ; int b = i-3 ; int c = i-4 ;
		result[i] = 0 ;
		if(a >= 0) result[i] += result[a] ;
		if(b >= 0) result[i] += result[b] ;
		if(c >= 0) result[i] += result[c] ;
	} 

	for(int i = 0 ; i <= 50 ; i++){
		std::cout << result[i] << std::endl; 
	}

	std::cout << result[n] << std::endl ;
}

int main(){
	
	int n ;
	std::cin >> n ;

	if(n == 0){
		std::cout << 0 << std::endl; 
		return 0 ;
	}

	solve2(n);




	return 0 ; 
}