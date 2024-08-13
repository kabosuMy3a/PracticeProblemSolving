#include <iostream>
int R, C ;
char ESM[3001][3001];
long long ans = 0 ;
int S[3001][3001];
int M[3001][3001];
long long divv = 1000000007 ;

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> R >> C ;
	for(int i = 1 ; i <= R  ; i++){
		for(int j = 1 ; j <= C ; j++){
			std::cin >> ESM[i][j] ;
			S[i][j] = 0 ; M[i][j] = 0;
		}
	}

	for(int i = R ; i >= 1 ; i--){
		for(int j = C ; j >= 1 ; j--){
			if((i + 1) <= R){
				S[i][j] += S[i+1][j] ;
				M[i][j] += M[i+1][j] ;
			} 
			if((j+1) <= C){
				S[i][j] += S[i][j+1] ;
				M[i][j] += M[i][j+1] ;
			} 

			if( ((i+1) <= R) && ((j+1) <= C)){
				S[i][j] -= S[i+1][j+1] ;
				M[i][j] -= M[i+1][j+1] ;
			}

			if(ESM[i][j] == 'E'){
				ans += (S[i][j] % divv);
			}
			else if(ESM[i][j] == 'S'){
			 	S[i][j] += M[i][j];
			 }
			else{
				 M[i][j] += 1;
			}
		}
	}

	std::cout << ans % divv << "\n";	

	return 0 ;
}
