#include <iostream>
#include <cstring>
#include <utility>

std::pair<int, int> folks[100000];
int group_start[100001];
int group_start_idx = 0 ;
int num_groups = 0;

void find_all_descending_groups(int N){
	for(int i = 0 ; i < N ; i++){
		int v = folks[i].second ;
		int num_can_meet = 1 ;
		while(i + num_can_meet < N){
			int next_v = folks[i + num_can_meet].second ;
			if(v > next_v){
				num_can_meet += 1 ;
				v = next_v;
			} else {
				break;
			}
		}
		group_start[group_start_idx++] = i ;	
		if(num_can_meet == 1){
			num_groups += 1; 
		} else {
			i = i + num_can_meet - 1;
		}
	}
	group_start[group_start_idx++] = N ;
}

bool check_mult_exceed_max(int a, int b){
	long long MAX_NUM = 1000000000 ;
	if(a == 0 || b == 0) return false ;

	int base = 1; 
	int a_digit = 0; int b_digit = 0;
	for(int i = 1 ; i <= 10 ; i++){
		base *= 10;
		if(a >= base) a_digit = i ;	
		if(b >= base) b_digit = i ;
	}

	if(a_digit + b_digit > 9) return true ;
	if(a_digit + b_digit == 9){
		long long ab = (long long)a * (long long)b ;
		if(ab > MAX_NUM) return true ; 
	}
	return false ;
}

bool is_folk_can_meet(std::pair<int, int> a, std::pair<int, int> b, int T){
	int p1 = a.first ; int v1 = a.second ;
	int p2 = b.first ; int v2 = b.second ;
	if(check_mult_exceed_max(v1 - v2, T)) 
		return true ;

	if((v1 -v2) * T >= p2 -p1) 
		return true ;
	return false ;
}

void find_num_together_moving_after_T(int T){
	for(int i = 0 ; i < group_start_idx -1 ; i++){
		if(group_start[i] + 1  == group_start[i+1]) continue ;
		
		int j = group_start[i] ;
		num_groups += 1 ;

		while(j < group_start[i+1]-1){
			bool is_meet = is_folk_can_meet(folks[j], folks[j+1], T); 
			j +=  1;
			if(!is_meet) num_groups += 1;
		}
	}
} 

int main(){
	int N ; int T ; std::cin >> N >> T ;

	for(int i = 0 ; i < N ; i++){
		int p ; int v ; std::cin >> p >> v ;
		std::pair<int, int> folk = std::make_pair(p,v);
		folks[i] = folk;
	}

	find_all_descending_groups(N);
	find_num_together_moving_after_T(T);
	std::cout << num_groups <<std::endl;

	return 0 ; 
}