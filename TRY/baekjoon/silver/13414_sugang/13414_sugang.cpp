#include <queue>
#include <iostream>
#include <unordered_map>
#include <cstring>

std::queue<std::string> q ;
std::unordered_map<std::string,int> um ;

int main(){
    
    std::ios_base::sync_with_stdio(0x0);
    int personnel ; int N ;
    std::cin >> personnel >> N ;
    for(int i = 0 ; i < N ; i++){
        std::string id ; std::cin >> id ;
        q.push(id); 
        auto it = um.find(id);
        if(it == um.end()){
            um.insert({id,1});
        } else {
            um[id] += 1 ;
        }
    }   

    int num_enrolled = 0;
    while(!q.empty() && (num_enrolled < personnel)){
        std::string cur = q.front() ; q.pop();
        if(um[cur] > 1){
            um[cur] -= 1 ;
            continue ;
        }
        std::cout << cur << "\n";
        num_enrolled += 1;
    } 

    return 0; 
}