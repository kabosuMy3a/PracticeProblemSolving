#include <iostream>
#include <utility>
#include <iostream>

int N ;
std::pair<int, int> points[100000];

int main(){
    
    std::ios_base::sync_with_stdio(0x0);
    std::cin.tie(0x0); std::cout.tie(0x0);
    std::cin >> N ;
    for(int i = 0 ; i < N ; i++){
        int a ; int b;
        std::cin >> a >> b ;
        
        points[i] = std::make_pair(a,b);
    }
    
    std::sort(points, points+N);
    
    for(int i = 0 ; i < N ; i++){
       std::cout << points[i].first << " " << points[i].second << "\n";
    }
    
    
    return 0 ;
}