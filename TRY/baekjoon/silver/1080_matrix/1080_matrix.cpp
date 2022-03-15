#include <iostream>

int N, M ;
char cur[50][50];
char goal[50][50];

int main(){
	
	std::cin >> N >> M ; int flag = 1 ;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			std::cin >> cur[i][j];
		}
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			std::cin >> goal[i][j];
			if(cur[i][j] != goal[i][j]) flag = 0 ;
		}
	}

	if(flag){
		std::cout << 0 << "\n";
		return 0;
	} else if(N < 3 || M < 3) {
		std::cout << -1 << "\n";
		return 0 ;
	}


	int ans = 0 ;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){	
			if(cur[i][j] != goal[i][j]){
				if(i + 2 < N && j + 2 < M){
					for(int k = i ; k < i + 3 ; k++){
						for(int l = j ; l < j + 3 ; l++){
							if(cur[k][l] == '1') cur[k][l] = '0';
							else cur[k][l] = '1';
						}	
					}
					ans++ ;
				}
			}
		}
	}
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(cur[i][j] != goal[i][j]){
				std::cout << -1 << "\n";
				return 0 ;
			}
		}
	}
	std::cout << ans << "\n";

	return 0 ;
}