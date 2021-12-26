#include <iostream>

long long gcd(long long a, long long b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	long long a, b ;
	std::cin >> a >> b ;
	if(b > a){
		long long tmp = a ;
		a = b; b = tmp ;
	}
	std::cout << gcd(a, b) << "\n";

	return 0;
}
