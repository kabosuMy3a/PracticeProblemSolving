#include <iostream>
#include <algorithm>

#define R 0
#define G 1
#define B 2

int RGBmin[3][1001] ; 
//0 : min(R,G), 1: min(G,B), 2: min(R,B) 
int RGBcost[3][1001] ;

void setRGBmin(int i){
	if(i == 1){
		RGBmin[0][1] = std::min(RGBcost[R][1], RGBcost[G][1]);
		RGBmin[1][1] = std::min(RGBcost[G][1], RGBcost[B][1]);
		RGBmin[2][1] = std::min(RGBcost[R][1], RGBcost[B][1]);
	} else {
		int cur_min_with_R = RGBmin[1][i-1] + RGBcost[R][i] ;
		int cur_min_with_G = RGBmin[2][i-1] + RGBcost[G][i] ;
		int cur_min_with_B = RGBmin[0][i-1] + RGBcost[B][i] ;

		RGBmin[0][i] = std::min(cur_min_with_R, cur_min_with_G);
		RGBmin[1][i] = std::min(cur_min_with_G, cur_min_with_B);
		RGBmin[2][i] = std::min(cur_min_with_R, cur_min_with_B); 
	}
}

int main(){
	
	int N ; std::cin >> N;
	for(int i = 1 ; i <= N ; i++){
		int r, g, b ; std::cin >> r >> g >> b;
		RGBcost[R][i] = r ;
		RGBcost[G][i] = g ;
		RGBcost[B][i] = b ;
	}

	for(int i = 1 ; i <= N ; i++) setRGBmin(i);
	int tmp = std::min(RGBmin[0][N], RGBmin[1][N]);
	std::cout << std::min(tmp, RGBmin[2][N]) << std::endl;

	return 0;
}