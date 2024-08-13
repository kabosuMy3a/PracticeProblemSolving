#include <iostream> 

int N, M ;
int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N >> M ; int ans ;
	for(int i = 0 ; i < N ; i++){

        int a ; int row[1000] ; 
		for(int j = 0 ; j < M ; j++){		
		   std::cin >> row[j] ;
		}

		for(int j = M - 1 ; j >= 0 ; j--){
			if(j == (M - 1)) a = row[j] ;
			else {
				if(row[j] <= a) a = row[j] - 1 ;
				else a = row[j];
			}
		}
		if(i == 0) ans = a ;
		else ans ^= a ;
	}

	if(ans == 0){
		std::cout << "cubelover" << "\n";
	} else {
		std::cout << "koosaga" << "\n";
	}

	return 0 ;
}