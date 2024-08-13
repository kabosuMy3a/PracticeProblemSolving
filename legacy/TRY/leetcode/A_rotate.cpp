#include <iostream>
#include <cmath>


long long ans = 0 ;
int NUM ;

int digits[9] ;

int main(){

	std::cin >> NUM;
	int num = NUM ;

	int a = 1 ;
	int i = 0 ;
	while(true){
		if(NUM < a) break;
		a = a * 10 ;
		i += 1 ;
	}

	for(int j = i ; j >= 0 ; j--){
		int div = pow(10,j);
		digits[j] = num / div;
		num %= div ;
	}

	int tmp = 0;
	for(int k = 1 ; k < i ; k++){
		for(int j = k ; j < i + k ; j++){
			int idx = j;
			if(j >= i) idx = j % i ;
			tmp += digits[idx] * pow(10, j-k) ;
		}
		if(tmp == NUM) break; 
		ans += tmp ;
		tmp = 0 ;
	}	


	std::cout << ans + NUM << std::endl;

	return 0;
}