#include <iostream>
#include <stack>

int main(){
    std::ios_base::sync_with_stdio(0x0); std::cin.tie(0x0);
    int N ; std::cin >> N ;
    std::stack<int> st ; 
    for(int i = 0 ; i < N ; i++){
        std::string s ; std::cin >> s ;
        if(s == "push"){
            int a; std::cin >> a; 
            st.push(a);
        } else if(s == "pop"){
            if(st.empty()){
                std::cout << "-1\n" ;
            } else {
                std::cout << st.top() << "\n";
                st.pop();
            }
        } else if(s == "size"){
            std::cout << st.size() << "\n";
        } else if(s == "empty"){
            if(st.empty()){
                std::cout << 1 << "\n";
            } else {
                std::cout << 0 << "\n";
            }
        } else {
            if(st.empty()){
                std::cout << "-1\n" ;
            } else {
                std::cout << st.top() << "\n";
            }            
        }
    }
    
    
    return 0 ;
}}