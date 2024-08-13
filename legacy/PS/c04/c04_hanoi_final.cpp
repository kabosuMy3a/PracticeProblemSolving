#include <iostream>

int start[51] = {0} ;
int destination[51] = {0} ;

int N ; int K ;

long long original_ans[51] ;

long long f(int n){
	return original_ans[n];
}

long long solution = 0 ;

void set_destination(int i){
	if(i == 0)
		return ;

	int s = start[i+1];
	int d = destination[i+1];

	if(s != d){
		destination[i] = 6 - s - d ;
	} else {
		destination[i] = d ;
	}

	set_destination(i-1);
}

void move_if_need(int i){
	if(i == N+1)
		return ;

	int s = start[i];
	int d = destination[i];

	if(s != d){
		solution += 1 + f(i-1) ;
	}

	move_if_need(i+1);
}

int main(){

	original_ans[0] = 0 ;
	original_ans[1] = 1 ;
	for(int i = 2 ; i <= 50 ; i++){
		original_ans[i] = original_ans[i-1] * 2 + 1 ;
	}

	std::cin >> N >> K ;
	destination[N] = K ; 

	for(int i = 1 ; i <= 3 ; i++){
		int sz ; 
		std::cin >> sz ;
		for(int j = 1 ; j <= sz ; j++){
			int ring ; 
			std::cin >> ring ;
			start[ring] = i; 
		}
	}

	set_destination(N-1);
	move_if_need(1);

	std::cout << solution << std::endl; 
}
