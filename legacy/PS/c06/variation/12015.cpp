#include <iostream>
#include <algorithm>

int cards[1000000];


int lis[1000000];
int lis_sz ;

int s1[1000000];

int main(){
	
	int N ; 
	std::cin >> N;

	for(int i = 0 ; i < N ; i++){
		int a ;
		std::cin >> a;
		cards[i] =  a;
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

 	std::cout << lis_sz <<std::endl;
 	return 0;
}
