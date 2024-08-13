#include <iostream>
#include <cstdlib>
#include <chrono>

long long N ;
long long ans = 0 ;
int stalls[100000];


void get_ans(int s, int e){
	if((e-s) == 0) return ;
	if((e - s) == 1){
		ans += abs(stalls[s]);
	} else{	
		int cur_min = abs(stalls[s]) ;
		int cur_min_idx = s ; 
		for(int i = s ; i < e ; i++){
			if(cur_min > abs(stalls[i])){
				cur_min = abs(stalls[i]);
				cur_min_idx = i ;
			}
		}

		int cntl_val = stalls[cur_min_idx];
		for(int i = s ; i < e ; i++){
			stalls[i] -= cntl_val ;
		}

		ans += abs(cntl_val) ;

		get_ans(s, cur_min_idx);
		get_ans(cur_min_idx+1, e);
	}

}

int main(){
	std::ios_base::sync_with_stdio(0x0); 
	std::cin.tie(0x0);

	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int a ; std::cin >> a ;
		stalls[i] = a ;
	}
	for (int i = 0; i < N; i++){
		int b ; std::cin >> b;
		stalls[i] -= b ;
	}

	int prev = stalls[0] ; /* -1 = neg, 0 , 1 =pos */ 
	int start_idx = 0 ;
	if(N == 1){
		if(prev < 0) prev *= -1 ;
		std::cout << prev <<std::endl;
		return 0 ;
	}

	for(int i = 1 ; i < N ; i++){
		int cur = stalls[i] ;
		if(cur * prev <= 0){
			get_ans(start_idx, i);
			start_idx = i; 
		}
		prev = cur ;
	}

	get_ans(start_idx, N);

	std::cout << ans << std::endl;
	return 0 ;

}