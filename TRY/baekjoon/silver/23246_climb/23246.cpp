#include <iostream>
#include <vector>
#include <algorithm>

typedef struct {
    int mult ;
    int sum ;
    int bn ;
} Score ;

bool compare(const Score a, const Score b ){
    if(a.mult != b.mult)
        return a.mult < b.mult ;
    else if(a.sum != b.sum)
        return a.sum < b.sum ;
    else
        return a.bn < b.bn ;
}

int main(){
   
    int n ;
    std::cin >> n ;
    
    std::vector<Score> ranking ;
    
    for(int i = 0 ; i < n ; i++){
        int bn ;
        std::cin >> bn ;
        int a ; int b; int c;
        std::cin >> a >> b >> c;
        Score score = {a * b * c, a+b+c, bn};
        ranking.push_back(score);
    }
    
    sort(ranking.begin(), ranking.end(),compare);
    std::cout << ranking[0].bn << " " << ranking[1].bn << " " << ranking[2].bn << std::endl;
}