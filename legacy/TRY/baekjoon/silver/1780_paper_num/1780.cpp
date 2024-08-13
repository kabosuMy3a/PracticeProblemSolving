#include <iostream>

int paper[2200][2200];
int num_0 = 0 ; int num_1 = 0 ; int num_2 = 0 ;

bool check(int r, int c, int sz){
	int s = paper[r][c] ;

	for(int i = r ; i < r + sz ; i++){
		for(int j = c ; j < c + sz ; j++){
			if(paper[i][j] != s) return false ;
		}
	}

	if(s == -1) num_0++ ;
	if(s == 0) num_1++ ;
	if(s == 1) num_2++ ;

	return true ;
}

void cut(int r, int c, int sz){
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);
	//std::cout << r << "," << c << ": " << sz << "\n"; 
	if(check(r,c,sz)) return ;

	int nsz = sz/3 ;

	cut(r,c,nsz) ;
	cut(r+nsz, c, nsz);
	cut(r+(nsz * 2), c, nsz) ;

	cut(r,c + nsz,nsz) ;
	cut(r+nsz, c + nsz, nsz);
	cut(r+(nsz * 2), c + nsz , nsz) ;

	cut(r,c + (nsz * 2),nsz) ;
	cut(r+nsz, c + (nsz *2) , nsz);
	cut(r+(nsz * 2), c + (nsz *2) , nsz) ;

}

int main(){

	int N ; std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			std::cin >> paper[i][j];
		}
	}


	cut(0,0,N);
	std::cout << num_0 << "\n";
	std::cout << num_1 << "\n";
	std::cout << num_2 << "\n";

	return 0 ;
}