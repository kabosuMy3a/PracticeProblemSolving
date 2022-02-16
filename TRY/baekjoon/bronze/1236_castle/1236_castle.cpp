#include <iostream>
#include <algorithm>
int N, M ; char castle[50][50];
int main(){
    std::cin>> N >> M;
    for(int i = 0; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            std::cin >> castle[i][j];
        }
    }
    int c_need = 0 ; int r_need = 0 ;
    for(int i = 0 ; i < N ; i++){
        int flag = 0; 
        for(int j = 0 ; j < M ; j++){
            if(castle[i][j] == 'X') flag = 1;
        }
        if(!flag) r_need += 1; 
    }
    
    for(int i = 0 ; i< M ; i++){
        int flag= 0 ;
        for(int j = 0 ; j < N ; j++){
            if(castle[j][i] == 'X') flag = 1;
        }
        if(!flag) c_need += 1;
    }
    
    std::cout << std::max(r_need, c_need) << "\n";

    return 0;
}