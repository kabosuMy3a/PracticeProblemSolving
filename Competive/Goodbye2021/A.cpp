#include <iostream> 
#include <vector>
#include <cstring>

int N ; 
int prime[105];
std::vector<int> primes ;

int mult_prime[105] ;

int main(){
	prime[0] = 0 ; prime[1] = 0 ;

	for(int i = 2 ; i < 105 ; i++){
		prime[i] = 1;  
	}
	for(int i = 2; i < 105 ; i++){
		if(prime[i] == 0) continue ;
		int j = 2; 
		while(i * j <= 105){
			prime[i * j] = 0 ;
			j++ ;
		}
	}

	for(int i = 2 ; i < 105 ; i++){
		if(prime[i]) primes.push_back(i);
	}

	int j = 0 ;
	for(int i = 0 ; i < (int)primes.size() -1 ; i++){
		mult_prime[j++] = primes[i] * primes[i+1];
	}

	std::cin >> N ;

	for(int i = 0 ; i < j ; i++){
		if(N < mult_prime[i]){
		 std::cout << mult_prime[i] << "\n";
		 break;
		}
	}


	return 0 ;
}