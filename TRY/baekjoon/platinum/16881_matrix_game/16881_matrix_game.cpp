#include <iostream> 

int N, M ;
int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N >> M ; int ans ;
	for(int i = 0 ; i < N ; i++){

        int a ; int row[1000] ; int num_continuous_one = 0 ;
		for(int j = 0 ; j < M ; j++){		
		   std::cin >> row[j] ;
		}


		if(row[1] > 1){
			if(row[0] == 1) a = 0 ; 
			else a = row[0] - 1 ;
		}
		else {
			int k ;
			for(k = 1 ; k < M ; k++){
				if(row[k] == 1) num_continuous_one += 1;
				else break ; 
			}
			if(k == M){
				if(num_continuous_one % 2 == 0){	
					a = row[0] ;
				} else {
					a = row[0] - 1;
				}
			} else {
				if(num_continuous_one % 2 == 0) {
					a = row[0] - 1;
				} else {
					a = row[0] ;
				}
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