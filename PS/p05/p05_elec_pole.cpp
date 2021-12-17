#include <iostream>
#include <algorithm>
#include <vector>

int N; int K ;
int max_d ; int min_d = 1 ;
int d_lower_bound = 0 ;
int poles[100000] ;

int check_update(int d){
	int num_pole = 1 ;
	int prev = poles[0] ;
	for(int i = 1 ; i < N ; i++){
		int cur = poles[i];
		if(cur - prev >= d){
			prev = cur ;
			num_pole++ ;
		}
	}
	if(num_pole >= K){
		d_lower_bound = d ;
		return 1;
	}
	return 0 ;	
}

void find_d_lower_bound_with_binary_search(){

	int mid = (max_d + min_d)/2 ;
	int is_updated = check_update(mid);

	if(mid == min_d) return ;

	if(is_updated){
		min_d = mid + 1 ;
	} else {
		max_d = mid - 1 ;
	}

	find_d_lower_bound_with_binary_search();
}

int main(){

	std::cin >> N ; std::cin >> K ;
	for(int i = 0 ; i < N  ; i++){
		int pole ; scanf("%d", &pole);
		poles[i] = pole ;
	}

	std::sort(poles, poles + N);
	max_d = ((poles[N-1] - poles[0])/(K-1) + 1) + 1 ;
	find_d_lower_bound_with_binary_search();
	std::cout << d_lower_bound << std::endl ; 

	return 0 ;
}