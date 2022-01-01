#include <iostream>
#include <algorithm>

int K, N;
int A[40] ;

int gcd(int a, int b){
	if(a % b == 0) return b;
	else return gcd(b, a%b);
}

bool cmp(int a, int b){
	return a > b ;
}

int main(){
	std::cin >> K >> N ;
	for(int i = 0 ; i <  N ; i++){
		std::cin >> A[i];
	}

	std::sort(A, A+N, cmp);

	int cur = A[0] ;

	for(int i = 1 ; i < N ; i++){
		int g = gcd(cur, A[i]);
		cur = cur * A[i] / g ;
	}

	std::cout << cur - K << "\n";

	return 0;

}