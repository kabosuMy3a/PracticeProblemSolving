#include <iostream>
#include <cstring>

std::string s ;
std::string p ; 
int ans = 0 ;

int main(){
    std::getline(std::cin, s);
    std::getline(std::cin, p);
    for(int i = 0 ; i < s.length() ; i++){
        if(i + p.length() > s.length()) break; 
        std::string k =  s.substr(i, i + p.length());
        if(k == p){
            i + p.length();
            ans += 1;
        }
    }
    std::cout << ans << "\n";
    return 0 ;
}