#include <iostream>
#include <cstring>

int main(){
    int N ; std::cin >> N ;
    std::string p ; std::cin >> p;
    int star = 0 ;
    for(auto c : p){
        if(c == '*') break ;
        star++; 
    }
   
    std::string f = p.substr(0,star);
    std::string r = p.substr(star+1);

    for(int i = 0 ; i < N ; i++){
        std::string s ; std::cin >> s ;

        if(s.length() < f.length() + r.length()){
            std::cout << "NE" << "\n";
            continue ;
        }

        std::string ff = s.substr(0, f.length()) ;
        std::string rr = s.substr(s.length() - r.length(), s.length());
        if(f == ff && r == rr) std::cout << "DA" << "\n" ;
        else std::cout << "NE" << "\n" ; 
    }
    
    return 0 ;
}