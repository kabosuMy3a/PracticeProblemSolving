#include <iostream>

int board[9][9] ;

bool check(int r, int c ){
	for(int i = 0 ; i < 9 ; i++){
		if(board[r][i] == board[r][c] && i != c) return false ;
		if(board[i][c] == board[r][c] && i != r) return false ;
	}

	int box_start_r = (r / 3) * 3 ;
	int box_start_c = (c / 3) * 3 ;

	for(int i = box_start_r ; i < box_start_r + 3 ; i++){
		for(int j = box_start_c ; j < box_start_c + 3 ; j++){
			if(i == r && j == c) continue ;
			if(board[i][j] == board[r][c]) return false ;
		}
	}

	return true; 
}

void solve(int r, int c){
	if(c == 9){
		r = r + 1 ;
		c = 0 ;
	}

	if(r == 9){
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				std::cout << board[i][j] ;
			}
			std::cout <<"\n";
		}
		exit(0);
	}

	
	if(board[r][c] != 0){
		solve(r,c+1);
	} else {
		for(int i = 1 ; i <= 9 ; i++){
			board[r][c] = i ; 
			if(check(r,c)){
				solve(r,c+1);
			}
		}
		board[r][c] = 0 ;
	}

}

int main(){
	
	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			char c ; std::cin >> c;
			board[i][j] = c - '0';
		}
	}

	solve(0,0);

	return 0 ;
}