#include <iostream>
char mirror[100][100] ;
int main(){
    int N ; std::cin >> N ; int state ;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            std::cin >> mirror[i][j] ;
    std::cin >> state ;
    if(state == 0){
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                std::cout << mirror[i][j];
            }
            std::cout << "\n";
        }
    } else if(state == 1){
          for(int i = 0 ; i < N ; i++){
              for(int j = N -1 ; j >= 0 ; j--){
                  std::cout << mirror[i][j] ;
              }
              std::cout << "\n";
          }   
    } else {
        for(int i = N -1 ; i >= 0 ; i--){
            for(int j = 0 ; j < N ; j++){
                std::cout << mirror[i][j];
            }
            std::cout << "\n";
        }
    }
    
    return 0 ;
}
