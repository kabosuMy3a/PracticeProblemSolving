#include <iostream>
#include <algorithm>
#include <vector>

int cards[1000000];


int lis[1000000];
int lis_sz ;

int s1[1000000];

int s1_max = 0 ;
int s1_max_idx = 0 ; 

std::vector<int> ans ;


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
 		if(s1_max < idx){
 			s1_max = idx ;
 			s1_max_idx = i ;
 		}

 	}

 	int cur_s1 = s1_max ;
 	for(int i = s1_max_idx ; i >= 0 ; i--){
 		if(s1[i] == cur_s1){
 			ans.push_back(cards[i]);
 			cur_s1 -= 1;
 		}
 		if(cur_s1 == -1) break ; 
 	}

 	std::cout << ans.size() << std::endl;
 	
 	for(int i = ans.size() - 1 ; i >= 0 ; i--){
 		std::cout << ans[i] << " ";
 	}
 	std::cout << std::endl;

 	return 0;
}
