#include <iostream>
#include <vector>

std::vector<int> rods[3] ;
int N ; int K ;

long long original_ans[51] ;
long long f(int n){
	return original_ans[n];
}

int rod_find(N-1){
	
}

void set(int from, int to, int N){
	int aux = 3 - from - to ;

	if(N-1 != 0){
		int new_from = rod_find(N-1);
		if(from == to){
			set(new_from, to, N-1);
		} else {
			set(new_from, aux, N-1);
		}
	}

	ring_move(from, to, N);

}

int main(){

	original_ans[0] = 0 ;
	original_ans[1] = 1 ;
	for(int i = 2 ; i <= 50 ; i++){
		original_ans[i] = original_ans[i-1] * 2 + 1 ;
	}

	std::cin >> N >> K ;

	for(int i = 0 ; i < 3 ; i++){
		int sz ; 
		std::cin >> sz ;
		for(int j = 0 ; j < sz ; j++){
			int a ;
			std::cin>> a ;
			if(a == N && i == K-1){
				N -= 1;
				continue ;
			}
			rods[i].push_back(a);
		}
	}

	if(N == 0){
		std::cout << 0 << std::endl ;
		return 0 ;
	}

	int from = 0 ;
	for(int i = 0 ; i < 3 ; i++){
		if(rods[i][0] == N) 
			from = i ;
	}

	set(from, K-1, N);
	
	for(int i = 0 ; i < 3 ; i++){
		int sz = rods[i].size();
		for(int j = 0 ; j < sz ; j++){
			std::cout << rods[i][j] << " " ;
		}
		std::cout << std::endl; 
	}

}
