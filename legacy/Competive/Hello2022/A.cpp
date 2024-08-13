#include <iostream>

int d[9] ;
int digit[9] ;
int N ; int D ;

void print_ans(){
	int ans = 0; int c = 0;

	
	for(int i = 0 ; i < D ; i++){
		std::cout << digit[i] ;   
	}
	std::cout << "\n";

	for(int i = D - 1 ; i >= 0  ; i--){
		ans += digit[i] * d[c++] ;
	}
	std::cout << ans <<"\n";
}

int main(){

	std::cin >> N >> D ;
	if(D==2){
		if(N >= 2) std::cout << -1 << "\n";
		else std::cout << 2 << "\n";
		return 0 ;
	}

	d[0] = 1 ;
	for(int i = 1 ; i < D ; i++){
		d[i] = d[i-1] * D ;
	}

	int a = N / d[D-1] ;
	if(a >= D){
		std::cout << -1 << "\n" ;
		return 0;
	}

	N -= a * d[D-1] ;
	digit[0] = a ;  
	int digit_idx = 1 ;

	for(int i = D-2 ; i >= 0 ; i--){
		int b = N / d[i] ;
		digit[digit_idx++] = b;
		N -= b * d[i];
	}

	int origin_digit[9] ;
	for(int i = 0 ; i < digit_idx ; i++){
		origin_digit[i] = digit[i];
	}

	if(digit[0] == 0){
		digit[0] = 1; digit[1] = 0; int dg = 2;
		for(int i = 2 ; i < digit_idx ; i++){
			digit[i] = dg++;
		}
		print_ans();
		return 0 ;
	}

	int is_first = 1 ;
	while(true){
		/*
		for(int i = 0 ; i < digit_idx ; i++){
			std::cout << digit[i] ;   
		}
		std::cout << "\n";*/

		int used_digit[10] = {0,} ; 
		int next_idx = digit_idx - 1;
		int passed = 1 ; int cut = -1 ;
		for(int i = 0 ; i < digit_idx ; i++){
			int cur = digit[i] ;
			used_digit[cur] += 1;
			if(used_digit[cur] >= 2){
				next_idx = i ;
				passed = 0 ;
			} 
			if(passed && digit[i] > origin_digit[i]){
				cut = i ;
				break;
			}		 
		}

		if(cut != -1){
			//std::cout << cut << "\n"; 
			for(int i = cut + 1 ; i < digit_idx ; i++){
				for(int j = 0 ; j < D ; j++){
					if(used_digit[j] == 0){
						digit[i] = j ;
						used_digit[j] = 1;
						break;
					}
				}
			}
			break;
		}

		if(!is_first && passed) break ; 
		if(is_first) is_first = 0;

		int is_exceed = 0; 
		for(int i = next_idx ; i >= 0 ; i--){
			digit[i] += 1;
			if(digit[i] == D){
				digit[i] = 0 ; 
				is_exceed = 1;
				if(i == 0){
					std::cout << -1 << "\n";
					return 0;
				}
			} else {
				is_exceed = 0 ;
			}
			if(!is_exceed) break; 
		}
	}


	print_ans();



	return 0;
}