#include <iostream>
#include <string>
#include <algorithm>

bool compare(std::string a, std::string b){
    if(a.size() != b.size()){
        return a.size() < b.size() ;
    }
    return a < b ;
}

std::string words[20000];

int main(){
    int N  ; std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        std::cin >> words[i] ;
    }
    
    std::sort(words, words + N, compare);

    std::string prev = words[0];
    std::cout << prev << "\n";
    for(int i = 1 ; i < N ; i++){
        if(prev == words[i]) continue ;
        std::cout << words[i] << "\n";
        prev = words[i];
    }
    
    
    
    return 0 ;
}