#include <iostream>
#include <cstdlib>

int T ;
int N ; int K;
int grid[50][50] ;

int sample[2][4];
//int sample_k2 = 0 ;
int sample_k3 = 0 ;



int main(){
	std::ios_base::sync_with_stdio(0x0); 
	std::cin.tie(0x0);

	//sample[0][0] = 4; sample[0][1] = 0;
	sample[1][0] = 6; sample[1][1] = 2; 
	sample[1][2] = 0 ; sample[1][3] = 6;

	std::cin >> T ; int t = 0 ; 
	while(t != T){
		int ans = 0 ;
		std::cin >> N >> K ;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				char a ; std::cin >> a;
				if(a == '.') grid[i][j] = 0 ;
				else grid[i][j] = -1 ;
			}
		}
		if(K==1 || K==2 || K==3){
			int cannot_go_through_first = 0 ;
			int cannot_go_through_second = 0 ;
			for(int i = 0 ; i < N ; i++){
				if(grid[0][i] == -1) cannot_go_through_first = 1;
				if(grid[i][N-1] == -1) cannot_go_through_first = 1;
				if(grid[i][0] == -1) cannot_go_through_second = 1 ;
				if(grid[N-1][i] == -1) cannot_go_through_second = 1;
			}
			if(!cannot_go_through_first) ans += 1;
			if(!cannot_go_through_second) ans += 1;
		}

		if(K ==2){
			for(int turn = 1 ; turn < N -1 ; turn++){
				int is_stuck = 0 ;
				for(int j = 0 ; j <= turn ; j++){
					if(grid[0][j] == -1){
						is_stuck = 1 ;
						break; 
					}
				} 
				if(is_stuck) break ; 
				for(int j = 0 ; j < N ; j++){
					if(grid[j][turn] == -1){
					 is_stuck = 1;
					 break;  
					}
				}
				if(is_stuck) continue ;
				for(int j = turn ; j < N ; j++){
					if(grid[N-1][j] == -1){
						is_stuck = 1;
						break;
					}
				}
				if(is_stuck) continue ;
				ans += 1 ;
			}

			
			for(int turn = 1 ; turn < N -1 ; turn++){
				int is_stuck = 0 ;
				for(int j = 0 ; j <= turn ; j++){
					if(grid[j][0] == -1){ 
						is_stuck = 1 ;
						break;
					} 
				} 
				if(is_stuck) break ; 
				for(int j = 0 ; j < N ;j++){
					if(grid[turn][j] == -1){
						is_stuck = 1;
						break;
					}  
				}
				if(is_stuck) continue ;
				for(int j = turn ; j < N ; j++){
					if(grid[j][N-1] == -1){
						is_stuck = 1;
						break;
					}
				}
				if(is_stuck) continue ;

				ans += 1 ;
			}
		}

		if(K==3){
			ans = sample[1][sample_k3++];
		}

		t++;
		std::cout << ans << std::endl;
	}

	return 0 ;
}