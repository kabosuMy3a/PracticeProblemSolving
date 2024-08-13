#include <iostream>

int people[51]; 

int main(){
	int N ; std::cin >> N ; 
	for(int i = 1 ; i <= N ; i++){
		std::cin >> people[i];
	}

	int ans = 0 ; int i = 0 ;
	while(true){

		int most_score = 0;
		int most_no = 0 ; 
		for(int i = 1 ; i <= N ; i++){
			if(most_score <= people[i]){
				most_no = i ;
				most_score = people[i] ;
			}
		}

		if(most_no == 1){
			std::cout << ans ;
			break; 
		} else {
			people[1] += 1;
			people[most_no] -= 1 ; 
			ans++ ;
		}
	}


	return 0 ;
}