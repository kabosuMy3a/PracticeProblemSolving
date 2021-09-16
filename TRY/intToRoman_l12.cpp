#include <iostream>
#include <vector>

int main(){

	std::string roman = "";

	int n ;
	std::cin >> n;

	int q = 0 ;

	std::vector<int> divisor = {1000, 900, 500, 400, 100, 90, 50, 40 ,10, 9 ,5 , 4, 1} ;
	std::vector<std::string> alpha = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

	for(int i = 0 ; i < divisor.size() ; i++){
		if((q = n/divisor[i]) > 0){
			for(int j = 0 ; j < q ; j++){
				roman += alpha[i] ;
			}

			n = n%divisor[i] ;
		}
	}

	std::cout << roman << std::endl ;

	return 0; 
}