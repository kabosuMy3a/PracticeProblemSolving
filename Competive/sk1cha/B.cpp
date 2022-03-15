#include <iostream>
#include <vector>

int nr[4] ;
int nc[4] ;
std::vector<int> ans[1000] ;

void fill_board(int N, int n, int r, int c, int step, int num){
	if(N % 2 == 0 && n == 1) return ;
	if(N % 2 == 1 && n == 0) return ;

	for(int i = 0 ; i < n -2 ; i++){
		//if(i == 0) continue ;
		r = r + nr[step] ;
		c  = c + nc[step] ;

		num++ ;
		ans[r][c] = num ;


	}
	if(step == 3) step = 0 ;
	else step += 1;
	std::cout << r << "," << c << "\n";
	fill_board(N, n-1, r, c, step, num) ;
}

int main(){
	int N ; std::cin >> N ; int clockwise ; std::cin >> clockwise ;
	if(clockwise){
		nr[0] = 0 ; nc[0] = 1 ;
		nr[1] = 1 ; nc[1] = 0 ;
		nr[2] = 0 ; nc[2] = -1 ;
		nr[3] = -1 ; nc[3] = 0 ;
 	} else {
 		nr[0] = 0 ; nc[0] = -1 ;
 		nr[1] = 1; nc[1] = 0 ;
 		nr[2] = 0 ; nc[2] = 1 ;
 		nr[3] = -1 ; nc[3] = 0 ;
 	}


    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            ans[i].push_back(0);
        }
    }

    if(clockwise){
    	fill_board(N, N, 0, 0, 0, 1);
    	fill_board(N, N, 0, N-1, 1, 1);
    	fill_board(N, N, N-1, N-1, 2, 1);
    	fill_board(N, N, N-1, 0, 3, 1);
    } else {
    	fill_board(N, N, 0, N-1, 0, 1);
    	fill_board(N, N, 0, 0 , 1, 1);
    	fill_board(N, N, N-1, 0, 2, 1);
    	fill_board(N, N, N-1, N-1, 3, 1);
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            std::cout << ans[i][j] << " " ;
        }
        std::cout << "\n";
    }



	return 0; 
}