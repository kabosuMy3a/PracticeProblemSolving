#include <iostream>
#include <algorithm>
#include <cassert>

int K, N;
int A[1000] ;
int B[1000] ;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

bool cmp(int a, int b){
	return a > b ;
}

int main(){
	std::cin >> N ;
	for(int i = 0 ; i <  N ; i++){
		std::cin >> A[i];
	}


	if(N == 1){
        std::cout << A[0] << "\n"; 
        return 0;
    }

	std::sort(A, A+N, cmp);

	if(N == 2){
        std::cout << A[0] - A[1] << "\n";
        return 0 ;
    }

    int ai = 0 ;
    int bi = 0 ;
    while(1){
        int prev = ai ;
        if(prev >= N-1) break ;
        while(A[prev] == A[ai]){
            ai++;
        }        
        if(ai >= N) break;
        B[bi++] = A[prev] - A[ai] ;
    }

    if(bi == 1){
    	std::cout << B[0] << "\n";
    	return 0 ;
    }

    int g = gcd(B[0], B[1]); 
	for(int i = 1 ; i < bi - 1 ; i++){
		g = gcd(g, B[i+1]);
	}

	std::cout << g << "\n";


	return 0;

}