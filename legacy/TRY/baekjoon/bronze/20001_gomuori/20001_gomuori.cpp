#include <iostream>
#include <cstring>

int main(){
    std::ios_base::sync_with_stdio(0x0);
    std::cin.tie(0x0);
    int left_problem = 0; 
    while(1){
        std::string s ;
        getline(std::cin, s); 
        if(s == "고무오리 디버깅 끝") break;
        if(s == "문제") left_problem += 1 ;
        else if(s == "고무오리"){
            if(left_problem == 0) left_problem += 2;
            else left_problem -= 1; 
        }
    }
    if(left_problem == 0) std::cout << "고무오리야 사랑해\n";
    else std::cout << "힝구\n"; 
   
    return 0 ;
}
