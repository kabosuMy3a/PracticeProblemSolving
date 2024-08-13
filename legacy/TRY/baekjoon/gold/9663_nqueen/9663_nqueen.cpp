#include <iostream>

int rows[15] ; //idx : pos row, value: pos column
int N ; int ans = 0 ;


bool check(int r){
	for(int i = 0 ; i < r ; i++){
		if(i == r) continue ;
		int cur_r = r ; int cur_c = rows[r] ;
		int cmp_r = i ; int cmp_c = rows[i] ;
		
		if(cur_c == cmp_c) return false ;
		if(abs(cur_r - cmp_r) == abs(cur_c - cmp_c)) return false ;
	}

	return true ;
}

void solve(int r){
	if(r == N){
		ans++ ;
		return ;
	}

	for(int i = 0 ; i < N ; i++){
		rows[r] = i ;
		if(check(r)) solve(r+1);
	}
}

int main(){
	for(int i = 1 ; i < 15 ; i++){
		N = i ;
		for(int j = 0 ; j < 15 ; j++) rows[j] = 0 ;
		ans = 0 ;
		solve(0);
		std::cout << ans << "\n";
	}
	return 0; 
}