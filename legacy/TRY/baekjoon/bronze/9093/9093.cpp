#include <iostream>
#include <string>
#include <algorithm>

int main(){
    int T ; std::cin >> T ; std::string s ; std::getline(std::cin, s);
    for(int t = 0 ; t < T ; t++){
        std::getline(std::cin, s);
        int prev = 0 ;
        for(int i = 0 ; i < s.length() ; i++){
            char c = s[i] ;
            if(c == ' '){
                std::reverse(s.begin()+ prev, s.begin()+i);
                prev = i + 1;
            } else if(i == s.length()-1){
                std::reverse(s.begin()+prev, s.end());
            }
        }
        std::cout << s <<"\n"; 
    }
    
    
    return 0 ;
}