#include <iostream>
#include <algorithm>

int main(){
	int T ; std::cin >> T ;
	for(int t = 1 ; t <= T ; t++){
		int N ; std::cin >> N ;
		int dice[100005];

		for(int i = 0 ; i < N ; i++) std::cin >> dice[i] ;
		std::sort(dice, dice+N);

		int cur = 0 ;
		for(int i = 0 ; i < N ; i++){
			cur += 1;
			if(dice[i] < cur){
				cur -= 1 ;
				continue; 
			}
		}
		
		std::cout << "Case #" << t << ": ";
		std::cout << cur << "\n";
	}

	return 0 ;
}