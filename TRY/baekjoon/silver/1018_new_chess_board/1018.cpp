#include <iostream>
#include <string>

char board[50][50];

int main(){
    
    int N, M; std::cin >> N >> M ;
    int min_ans = 65 ;

    for(int i = 0 ; i < N ; i++){
       std::string s ; std::cin >> s ;
       for(int j = 0 ; j < M ; j++){
           board[i][j] = s[j] ;
       }
    }
    
    for(int i = 0;  i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if((i + 8 <= N)&&(j+8 <= M)){
                for(int t = 0 ; t< 2 ; t++){
                    char wanna  ;
                    if(t == 0) wanna = 'B';
                    else wanna = 'W';
                    int ans = 0 ;
                    for(int r = i ; r < i+8 ; r++){
                        if(wanna == 'B') wanna = 'W';
                        else wanna = 'B'; 
                        for(int c = j ; c < j+8 ; c++){
                            if(wanna != board[r][c]){
                                ans++ ;
                            }
                            if(wanna == 'B') wanna = 'W';
                            else wanna = 'B'; 
                        } 
                    }
                    if(ans < min_ans) min_ans = ans ;
                }
            }
        }
    }
    std::cout << min_ans ;
    return 0 ;
}