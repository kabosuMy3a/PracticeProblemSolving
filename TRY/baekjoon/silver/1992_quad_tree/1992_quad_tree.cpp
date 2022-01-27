#include <iostream>
#include <cstring>

int N ;
char movie[65][65];
std::string ans ;


std::string sep(int r, int c, int sz){

	if(sz == 1){
	 std::string s ;
	 s += movie[r][c];
	 return s ; 
	}

	std::string quad4, quad1, quad2 ,quad3 ;

	quad4 = sep(r, c, sz/2);
	quad1 = sep(r, c + sz/2, sz/2);
	quad2 = sep(r + sz/2, c + sz/2, sz/2);
	quad3 = sep(r + sz/2, c, sz/2);

	if(quad1 == "0" && quad2 == "0" && quad3 == "0" && quad4 == "0" ) return "0";
	if(quad1 == "1" && quad2 == "1" && quad3 == "1" && quad4 == "1" ) return "1";

	return "(" + quad4 + quad1 + quad3 + quad2 + ")";

}



int main(){

	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N ;
	for(int i = 1 ; i <= N ; i++)
		for(int j = 1 ; j <= N ; j++){
			char a ; std::cin >> a ; 
			movie[i][j] = a;
		}

	std::cout << sep(1, 1, N) << "\n" ;
	return 0; 
}