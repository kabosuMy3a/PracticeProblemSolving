#include <iostream>

int applepie[200000] ;
int N, K ; 

int main(){
	
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N >> K ;
	for(int i = 0 ; i < N ; i++){
		int a ; std::cin >> a;
		applepie[i] = a ;
		applepie[i+N] = a ;
	}

	int cur = 0 ; int sum = 0 ; int sum_max = 0 ;
	for(int i = 0 ; i < N + K  ; i++){
		if(cur != K){
			 cur++ ;
			 sum += applepie[i];
		} else {
			sum += applepie[i] ;
			sum -= applepie[i-K];
			if(sum_max < sum) sum_max = sum ;
		}
	}

	std::cout << sum_max << "\n" ;
	return 0 ;
}