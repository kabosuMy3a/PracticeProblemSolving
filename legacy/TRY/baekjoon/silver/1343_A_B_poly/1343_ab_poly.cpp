#include <iostream>
#include <cstring>

std::string s; 
std::string ans ;
int main(){
    std::cin >> s;
    int num_x = 0;
    for(auto c : s){
        if(c == 'X') num_x++;
        if(c == '.'){
            if(num_x % 2 == 1){
                std::cout << -1 << "\n";
                return 0 ;
            }
            while(num_x > 0){
                if(num_x >= 4){
                    ans += "AAAA";
                    num_x -= 4 ;
                } else {
                    ans += "BB" ;
                    num_x -= 2 ;
                }
            }
            num_x = 0;
            ans += "."; 
        }
    }
    if(num_x != 0){
            if(num_x % 2 == 1){
                std::cout << -1 << "\n";
                return 0 ;
            }
            while(num_x > 0){
                if(num_x >= 4){
                    ans += "AAAA";
                    num_x -= 4 ;
                } else {
                    ans += "BB" ;
                    num_x -= 2 ;
                }
            } 
    }
    
    std::cout << ans << "\n";
    
    return 0 ;
}