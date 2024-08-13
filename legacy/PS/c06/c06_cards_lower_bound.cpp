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

void print_solutions(int N){
 		int solution = 0 ;
	 	for(int i = 0 ; i < N ; i++){
	 		int cur_sum = s1[i] + s2[i] + 1; 
 			if(cur_sum > solution)
 				solution = cur_sum ;
 		}
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
 		int idx = std::lower_bound(lis, lis + lis_sz, cur) - lis;

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
 		int idx = std::lower_bound(lis, lis + lis_sz, cur) - lis;

 		if(idx == lis_sz){
 			lis_sz += 1;
 		}

 	 	lis[idx] = cur ;
 		s2[i] = idx;

 	}

 	revert(N);
 	print_solutions(N);
 	return 0;
}
