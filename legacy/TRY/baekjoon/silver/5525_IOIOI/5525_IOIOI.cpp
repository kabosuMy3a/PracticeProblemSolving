#include <iostream>
#include <cstring>
#include <vector>

std::string s ;
std::vector<int> rank_list ;

int main(){
    int N ; std::cin >> N ;
    int K ; std::cin >> K ;
    std::cin >> s ;
    char next = 'I' ;
    int rank = 0 ;
    int ans = 0 ;
    for(auto c : s){
       if(c == next){
           rank += 1;
           if(next == 'I') next = 'O';
           else if(next == 'O') next = 'I';
       } else {
           if(rank >= 3){
               rank_list.push_back(rank);
           }
           
           if(c =='I'){
                rank = 1; 
                next = 'O';
           } else{
                rank = 0;
                next = 'I';
           }

       }
    }
    if(rank >= 3) rank_list.push_back(rank);
    
    for(int cur_rank : rank_list){
        int M = (cur_rank - 1)/2 ;
        int a = (2 * M) + 1 ;
        int b = (2 * N) + 1 ;
        if(a >= b){
            ans += ((a - b)/2) + 1;
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}