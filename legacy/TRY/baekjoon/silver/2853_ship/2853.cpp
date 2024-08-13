#include <iostream>
#include <algorithm>

int days[5000];
int checked[5000]= {0,} ;

int main(){
	int N ; std::cin >> N ;
	int checked_num = 0;
	int ans = 0 ;

	for(int i = 0 ; i < N ; i++){
		std::cin >> days[i] ;
	}

	while(1){
		if(checked_num == N-1) break ;
		int dist ;
		for(int i = 1 ; i < N ; i++){
			if(checked[i] == 0){
				dist = days[i] - 1;
				checked[i] = 1 ;
				checked_num++ ;
				ans++ ;
				break;
			}
		}

		for(int i = 1 ; i < N ; i++){
			if((days[i] -1) % dist == 0){
				if(checked[i] == 0) {
					checked_num++ ;
					checked[i] = 1 ;
				}
			}
		}
	}

	std::cout << ans ;

	return 0 ;
}
