#include <iostream>
#include <cmath>

int nonary_to_decimal(int nonary){
	
	int i ;
	int decimal = 0 ;

	for(i = 0 ; pow(10, i) <= nonary ; i++){
	}

	while(i != 0){

		int divisor = pow(10, --i);
		int q = nonary / divisor ; 
		nonary = nonary % divisor ;

		if(q > 4) q -= 1 ;

		decimal += pow(9, i) * q ; 

	}

	return decimal ; 

}


int main(){

	int nonary ; 
	std::cin >> nonary ;

	int decimal = nonary_to_decimal(nonary);
	std::cout << decimal << std::endl;

	return 0; 
}
