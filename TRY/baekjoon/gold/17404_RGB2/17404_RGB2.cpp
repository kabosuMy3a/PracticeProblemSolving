#include <iostream>
#include <algorithm>

#define R 0
#define G 1
#define B 2

int N ;
int RGBmin[3][1001] ; 
//0 : min(R,G), 1: min(G,B), 2: min(R,B) 
int RGBcost[3][1001] ;

void setRGBmin(int first_color, int i){
    
	if(i == 1){
        if(first_color == R){
            RGBmin[0][1] = RGBcost[R][i] ;
            RGBmin[1][1] = 1001 ;
            RGBmin[2][1] = RGBcost[R][i] ;
        } else if(first_color == G){
            RGBmin[0][1] = RGBcost[G][i] ;
            RGBmin[1][1] = RGBcost[G][i] ;
            RGBmin[2][1] = 1001 ;
        } else {
            RGBmin[0][1] = 1001 ;
            RGBmin[1][1] = RGBcost[B][i] ;
            RGBmin[2][1] = RGBcost[B][i] ;   
        }

	} else {
		int cur_min_with_R = RGBmin[1][i-1] + RGBcost[R][i] ;
		int cur_min_with_G = RGBmin[2][i-1] + RGBcost[G][i] ;
		int cur_min_with_B = RGBmin[0][i-1] + RGBcost[B][i] ;

		RGBmin[0][i] = std::min(cur_min_with_R, cur_min_with_G);
		RGBmin[1][i] = std::min(cur_min_with_G, cur_min_with_B);
		RGBmin[2][i] = std::min(cur_min_with_R, cur_min_with_B); 
        
        if(i == N){
            if(first_color == R){
                RGBmin[0][i] = cur_min_with_G;
                RGBmin[2][i] = cur_min_with_B; 
            } else if(first_color == G){
                RGBmin[0][i] = cur_min_with_R;
		        RGBmin[1][i] = cur_min_with_B;
            } else {
        		RGBmin[1][i] = cur_min_with_G;
        		RGBmin[2][i] = cur_min_with_R;
            }
        }
	}
}

int main(){
	
	std::cin >> N;
	for(int i = 1 ; i <= N ; i++){
		int r, g, b ; std::cin >> r >> g >> b;
		RGBcost[R][i] = r ;
		RGBcost[G][i] = g ;
		RGBcost[B][i] = b ;
	}

    int tmp;
    for(int c ; c < 3 ; c++){
	    for(int i = 1 ; i <= N ; i++) setRGBmin(c, i);
        if(c == 0) tmp = std::min(RGBmin[0][N], RGBmin[1][N]);
        else{
            tmp = std::min(tmp, RGBmin[0][N]);
            tmp = std::min(tmp, RGBmin[1][N]);
        }
        tmp = std::min(tmp, RGBmin[2][N]) ; 
    }
    
	std::cout << tmp << std::endl;

	return 0;
}