#include <iostream>

int N ; 
int steps[301];
int max_score[301];

int main(){
    std::cin >> N ;
    for(int i = 1 ; i <= N ; i++) std::cin >> steps[i];
    
    max_score[0] = 0 ;
    max_score[1] = steps[1] ;
    max_score[2] = steps[1] + steps[2] ;
   
    for(int i = 3 ; i <= N ; i++){
        max_score[i] = std::max(max_score[i-3] + steps[i-1], max_score[i-2]) ;
        max_score[i] += steps[i] ;
    }
    
    std::cout << max_score[N] << "\n";  
    return 0 ;
}