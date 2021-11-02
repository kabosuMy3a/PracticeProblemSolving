#include <iostream>
#include <algorithm>

int cards[50000];
int cards_reversded[50000];

int lis[50000];
int lis_sz ;

int s1[50000];
int s2[50000];

void revert(int N){
	int f = 0 ;
	int r = N-1 ;

	while(f < r){
		int temp ; temp = s2[f];
		s2[f] = s2[r]; s2[r] = temp ;
		f++ ; r--;	
	}
}

void print_cards(int N){

		for(int i = 0 ; i < N ; i++){
			std::cout << cards[i] << " " ;
 		}
 		std::cout << "\n";

 		for(int i = 0 ; i < N ; i++){
 			std::cout << cards_reversded[i] << " ";
 		}
 		std::cout << "\ns1\n";

 		for(int i = 0 ; i < N ; i++){
 			std::cout << s1[i] << " ";
 		}
 		std::cout << "\ns2\n";

 		for(int i = 0 ; i < N ; i++){
 			std::cout << s2[i] << " ";
 		}
 		std::cout << "\n";

 		int solution = 0 ;
	 	for(int i = 0 ; i < N ; i++){
	 		int cur_sum = s1[i] + s2[i] + 1; 
 			std::cout << cur_sum << " "; 
 			if(cur_sum > solution)
 				solution = cur_sum ;
 		}
 		std::cout << "\n";
 		std::cout << solution << std::endl;
}

/*
TODO:: 
int lower_bound(){

}
*/

int main(){
	
	int N ; 
	std::cin >> N;

	for(int i = 0 ; i < N ; i++){
		int a ;
		std::cin >> a;
		cards[i] =  a;
		cards_reversded[N-i-1] = a ; 
 	} 

 	s1[0] = 0 ; 
 	lis[0] = cards[0];
 	lis_sz = 1 ;

 	for(int i = 1 ; i < N ; i++){
 		int cur = cards[i] ;
 		long idx = std::lower_bound(lis, lis + lis_sz, cur) - lis;

 		if(idx == lis_sz){
 			lis_sz += 1;
 		}

 	 	lis[idx] = cur ;
 		s1[i] = idx;

 	}

 	s2[0] = 0 ;
 	lis[0] = cards_reversded[0] ;
 	lis_sz = 1 ;

 	 for(int i = 1 ; i < N ; i++){
 		int cur = cards_reversded[i] ;
 		long idx = std::lower_bound(lis, lis + lis_sz, cur) - lis;

 		if(idx == lis_sz){
 			lis_sz += 1;
 		}

 	 	lis[idx] = cur ;
 		s2[i] = idx;

 	}

 	revert(N);
 	print_cards(N);
}


/*

문제: 카드를 오름차순으로 받다가, 언제부터 내림차순으로 받아야 최댓값이 되는가

아이디어:
모든 부분을 카드를 내림차순으로 받는 터닝포인트로 생각할 수 있음
각 카드를 기준으로 왼쪽에서 얻을 수 있는 최댓값과 오른쪽에서 얻을 수 있는 최댓값을 더하고 가장 큰 값을 찾음

왼쪽에서 얻을 수 있는 최댓값과 오른쪽에서 얻을 수 있는 최댓값은 DP를 사용하여 최적화 할 수 있다.

*/