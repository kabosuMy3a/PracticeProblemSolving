 #include <iostream>
#include <deque>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);
    int N ; std::cin >> N ;
    std::deque<int> dq ;
    
    for(int i = 0 ; i < N ; i++){
        std::string s;  std::cin >> s ;
        if(s == "push_front"){
            int a ; std::cin >> a;
            dq.push_front(a);
        }

        if(s == "push_back"){
        	int a; std::cin >> a;
        	dq.push_back(a) ;
        }

        if(s == "pop_front"){
            if(dq.empty()){
                std::cout << -1 << "\n";
            } else {
                std::cout << dq.front() << "\n";
                dq.pop_front();
            }
        }

        if(s == "pop_back"){
            if(dq.empty()){
                std::cout << -1 << "\n";
            } else {
                std::cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        
        if(s == "size"){
            std::cout << dq.size() << "\n";
        }
        
        if(s == "empty"){
            if(dq.empty()){
                std::cout << 1 << "\n";
            } else {
                std::cout << 0 << "\n";
            }
        }
        
        if(s == "front"){
            if(dq.empty()){
                std::cout << -1 << "\n";
            } else {
                std::cout << dq.front() << "\n"; 
            }
        }
        
        if(s == "back"){
            if(dq.empty()){
                std::cout << -1 << "\n";
            } else {
                std::cout << dq.back() <<"\n";
            }
        }
    }
    
    
    return 0 ;
}
