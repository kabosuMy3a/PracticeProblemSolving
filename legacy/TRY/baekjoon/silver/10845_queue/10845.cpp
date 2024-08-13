#include <iostream>
#include <queue>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);
    int N ; std::cin >> N ;
    std::queue<int> q ;
    int last = -1 ;
    
    for(int i = 0 ; i < N ; i++){
        std::string s;  std::cin >> s ;
        if(s == "push"){
            int a ; std::cin >> a;
            q.push(a);
            last = a ;
        }
        if(s == "pop"){
            if(q.empty()){
                std::cout << -1 << "\n";
            } else {
                std::cout << q.front() << "\n";
                q.pop();
            }
        }
        
        if(s == "size"){
            std::cout << q.size() << "\n";
        }
        
        if(s == "empty"){
            if(q.empty()){
                std::cout << 1 << "\n";
            } else {
                std::cout << 0 << "\n";
            }
        }
        
        if(s == "front"){
            if(q.empty()){
                std::cout << -1 << "\n";
            } else {
                std::cout << q.front() << "\n"; 
            }
        }
        
        if(s == "back"){
            if(q.empty()){
                std::cout << -1 << "\n";
            } else {
                std::cout << last <<"\n";
            }
        }
    }
    
    
    return 0 ;
}
