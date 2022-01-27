#include <iostream>
#include <cstring>

std::string ans ;

int main(){
    std::ios_base::sync_with_stdio(0x0);
    int N ; std::cin >> N;
    for(int i = 0 ; i < N ; i++){
        std::string s ; std::cin >> s;
        if(i == 0){
            ans = s; 
            continue ;
        }
        int cur = 0 ;
        for(auto c : s){
          if(ans[cur] != c) ans[cur] = '?';
          cur++;
        }
    }
    
    std::cout << ans << "\n";
    return 0 ;
}