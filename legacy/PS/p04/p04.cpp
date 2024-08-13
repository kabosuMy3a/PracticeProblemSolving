#include <iostream>
#include <cmath>

int main(){

	double a = 2132215.0 ;
	double b = 233424.0;
	
	double c = 0;
	double d = 0;

	int ai = 2132215 ;
	int bi = 233424 ;
	int ci = 0 ;



	double man7 = (long double) 10007.0;

	for(int i = 0 ; i < 20000 ; i++){
		d += a+b ;
		c += fmod(fmod(a, man7) + fmod(b, man7), man7);
		ci += fmod(fmod(ai, 10007) + fmod(bi, 10007), 10007);
	}


 	bool ans = ci == c ;

	double da = -9876543210.12345;
	double daa = fmod(da, man7);





	if(c == (long long)c){
		std::cout << (long long)c << " " << (long long) d << std::endl ;
	}

	if(daa == (daa)){
		std::cout << std::fixed ;
		std::cout.precision(5);
		std::cout << da << std::endl;
		std::cout << daa << std::endl;
		std::cout << daa+ daa << std::endl;
	}
	



	return 0;
}