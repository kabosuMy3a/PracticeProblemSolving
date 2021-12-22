#include <iostream>
#include <cstring>

std::string s ;

int main(){

    std::getline(std::cin, s);
    char ans[4] = {'U', 'C', 'P', 'C'};
    int i = 0 ;
    for(auto c : s){
        if(c == ans[i]) i++;
        if(i == 4) break ;
    }

    if(i == 4) std::cout << "I love UCPC\n" ;
    else std::cout << "I hate UCPC\n" ;
    return 0 ;
}