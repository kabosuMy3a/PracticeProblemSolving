#include <iostream>
#include <cstring>
std::string s ;
int main(){
    std::cin >> s;
    char prev = 'a' ; int next_should = 0; int flag = 0;
    int ans = 0 ;
    for(auto c : s){
        if(next_should){
            next_should = 0 ; 
            if(c== '='){
                ans--; 
                flag = 1 ;
            }
        }
        if(c == '-' && (prev == 'c' || prev == 'd')) flag = 1;
        if(c == '=' && (prev == 'z' || prev == 's' || prev == 'c')) flag = 1;
        if(c == 'j' && (prev == 'l' || prev == 'n')) flag = 1;
        if(c == 'z' && (prev == 'd')) next_should = 1 ;
        
        prev = c ;
        if(flag){
            flag = 0 ;
            continue ;
        }
        ans++ ;   
    }
    std::cout << ans << "\n";
    
    return 0;
}
