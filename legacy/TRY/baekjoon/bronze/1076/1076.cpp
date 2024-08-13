#include <iostream>
#include <map>
#include <utility>
#include <cstring>

std::map<std::string, std::pair<long long, long long>> color_table ;
std::string colors[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"} ; 

int main(){
    long long x = 1 ;
    for(int i = 0 ; i < 10 ; i++){
        if(i != 0) x *= 10 ;
        color_table.insert({colors[i], {i, x}});
    }
    std::string a, b, c ;
    std::cin >> a >> b >> c ;
    long long ans = 0 ;
    ans += color_table[a].first * 10 ;
    ans += color_table[b].first ;
    ans *= color_table[c].second ; 
    std::cout << ans << "\n";    
    return 0 ;
}
