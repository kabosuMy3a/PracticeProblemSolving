#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> um ;


int main(){
    
    int N ; std::cin >> N ;
    for(int i = 0 ; i < N ; i++){
        std::string title ; std::cin >> title;
        auto it = um.find(title);
        if(it == um.end()){
            um.insert({title,1});
        } else {
            um[title] += 1 ;
        }
    }

    int most  = 0 ; std::string most_title ;
    for(const auto& it : um){
        if(most < it.second){
            most = it.second ;
            most_title = it.first;
        } else if(most == it.second){
            if(most_title > it.first){
                most_title = it.first;
            }
        }
    }

    std::cout << most_title ;

    
    return 0 ;
}