#include <iostream>

int cards[50000];
int cards_reversded[50000];

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

void print_solution(int N){
 		int solution = 0 ;
	 	for(int i = 0 ; i < N ; i++){
	 		int cur_sum = s1[i] + s2[i] + 1; 
 			if(cur_sum > solution)
 				solution = cur_sum ;
 		}
 		std::cout << solution << std::endl;
}

int main(){
	
	int N ; 
	std::cin >> N;

	for(int i = 0 ; i < N ; i++){
		int a ;
		std::cin >> a;
		cards[i] =  a;
		cards_reversded[N-i-1] = a ; 
 	} 

 	s1[0] = 0 ; s2[0] = 0 ;

 	for(int i = 1 ; i < N ; i++){
 		int s1_max = 0 ;
 		int s2_max = 0 ;
 		for(int j = 0 ; j < i ; j++){
 			if(cards[i] > cards[j]){
 				int s1_cur = s1[j] + 1;
 				if(s1_max < s1_cur) s1_max = s1_cur ;
 			}

 			if(cards_reversded[i] > cards_reversded[j]){
 				int s2_cur = s2[j] + 1;
 				if(s2_max < s2_cur) s2_max = s2_cur ;
 			}
 		}

 		s1[i] = s1_max ;
 		s2[i] = s2_max ;
 	}

 	revert(N);
 	print_solution(N);
}
