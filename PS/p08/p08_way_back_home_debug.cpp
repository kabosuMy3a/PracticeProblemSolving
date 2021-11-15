#include <iostream>
#include <cstring>
#include <utility>

std::pair<int, int> folks[100000];
int num_groups = 0;

bool check_mult_exceed_max(int a, int b){
	long long MAX_NUM = 1000000000 ;
	if(a <= 0 || b <= 0) return false ;

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


	std::cout <<"(" << v1 << " - " << v2  << ")* " << T << " >= " << p2 << "-" <<  p1 << std::endl;
	std::cout <<(v1-v2) * T << " >= " << p2-p1 <<std::endl; 

	if((v1-v2) < 0) 
		return false; 
	if((v1 -v2) * T >= p2 -p1) 
		return true ;
	return false ;
}

void find_num_together_moving_after_T(int N, int T){
	std::pair<int, int> last = folks[N-1];
	num_groups += 1;
	for(int i = N-1 ; i > 0 ; i--){
		std::pair<int, int> cur = folks[i-1];
		if(!is_folk_can_meet(cur,last,T)){
			last = cur ;
			num_groups += 1;
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

	find_num_together_moving_after_T(N, T);

	std::cout << num_groups <<std::endl;

	return 0 ; 
}