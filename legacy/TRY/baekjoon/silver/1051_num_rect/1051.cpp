#include <iostream>
#include <utility>

int R, C ;
char square[50][50] ;

int find_biggest(int r, int c){
	int sz = 0 ;
	int rst = 0 ;
	while(1){
		if(r + sz >= R || c + sz >= C) break;

		std::pair<int,int> lt = {r,c};
		std::pair<int,int> rt = {r,c+sz};
		std::pair<int,int> lb = {r+sz,c};
		std::pair<int,int> rb = {r+sz,c+sz};

		sz++;

		//std::cout << r << "," << c << " : " << sz << "\n";

		if((square[lt.first][lt.second] == square[rt.first][rt.second]) 
			&& (square[lt.first][lt.second] == square[lb.first][lb.second])
			&& (square[lt.first][lt.second] == square[rb.first][rb.second]))
				rst = sz ;

	}

	return rst ;
}

int main(){
	std::cin >> R >> C ;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			std::cin >> square[i][j];
		}
	}	

	int ans = 0 ;
	for(int r = 0 ; r < R ; r++){
		for(int c = 0 ; c < C ; c++){
			int cur = find_biggest(r,c);
			if(ans < cur) ans = cur ;
		}
	}


	std::cout << ans * ans << "\n" ;

	return 0;
}