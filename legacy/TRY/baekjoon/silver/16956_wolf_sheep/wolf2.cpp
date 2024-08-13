#include <iostream> 
#include <utility>

char field[501][501]; 
int R, C ;

std::pair<int, int> p_wolves[500];
int wolves_num = 0 ;

int main(){
   
   std::cin >> R >> C ;
   for(int i = 1 ; i <= R ; i++){
       for(int j = 1 ; j <= C ; j++){
           std::cin >> field[i][j] ;
           if(field[i][j] == 'W'){
               p_wolves[wolves_num++] = {i, j} ;
           }   
       }
   }
   
   for(int i = 0 ; i < wolves_num ; i++){
       std::pair<int, int> cur = p_wolves[i];
       int cur_x = cur.first ;
       int cur_y = cur.second ;
       if(cur_x -1 >= 1){
           if(field[cur_x - 1][cur_y] == 'S'){
               std::cout << 0 << "\n";
               return 0;
           } else if(field[cur_x -1][cur_y] == '.'){
               field[cur_x -1][cur_y] = 'D' ;
           }
       }
       
       if(cur_x +1 <= R){
           if(field[cur_x + 1][cur_y] == 'S'){
               std::cout << 0 << "\n";
               return 0;
           } else if(field[cur_x +1][cur_y] == '.'){
               field[cur_x +1][cur_y] = 'D';
           }
       }
       
       if(cur_y -1 >= 1){
           if(field[cur_x][cur_y-1] == 'S'){    
               std::cout << 0 << "\n";
               return 0;
           } else if(field[cur_x][cur_y-1] == '.'){
               field[cur_x][cur_y-1] = 'D';
           }
       }
       
       if(cur_y +1 <= C){
           if(field[cur_x][cur_y+1] == 'S'){    
               std::cout << 0 << "\n";
               return 0;
           } else if(field[cur_x][cur_y+1] == '.'){
               field[cur_x][cur_y+1] = 'D';
           }                  
       }
   }
    
   std::cout << 1 << "\n"; 
   for(int i = 1 ; i <= R ; i++){
       for(int j = 1 ; j <= C ; j++){
           std::cout << field[i][j] ;
       }
       std::cout << "\n";
   }

    
   return 0;
}