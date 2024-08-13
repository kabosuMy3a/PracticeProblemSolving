#include <iostream> 
#include <utility>

char field[501][501]; 
int R, C ;

std::pair<int, int> p_wolves[500];
int wolves_num = 0 ;

int r[4] = {-1, 1, 0, 0};
int c[4] = {0, 0, -1, 1};

int main(){
   
   std::cin >> R >> C ;
   for(int i = 1 ; i <= R ; i++){
       for(int j = 1 ; j <= C ; j++){
           std::cin >> field[i][j] ;
           if(field[i][j] == 'S'){
               p_wolves[wolves_num++] = {i, j} ;
           }   
       }
   }
    
   for(int i = 0 ; i < wolves_num ; i++){
       std::pair<int, int> cur = p_wolves[i] ;
       for(int j = 0 ; j < 4 ; j++){
           int nr = cur.first + r[j] ;
           int nc = cur.second + c[j] ;
           if((1 <= nr && nr <= R) && (1 <= nc && nc <= C)){
               if(field[nr][nc] == 'W'){
                   std::cout << 0 << "\n";
                   return 0 ;
               } else if(field[nr][nc] == '.'){
                   field[nr][nc] = 'D' ;
               }
           }
       }
   }
    
   std::cout << 1 << "\n";
   for(int i = 1 ; i <= R ; i++){
       for(int j = 1 ; j <= C ; j++){
           std::cout << field[i][j] ;
       }
       std::cout << "\n" ;
   }
   return 0;
}