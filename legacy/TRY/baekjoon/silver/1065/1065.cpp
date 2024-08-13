#include <iostream>

int ans[1000] ;

bool decide(int a){
    int d1, d2, d3 ;
    d1 = a / 100 ; a %= 100 ;
    d2 = a / 10 ; a %= 10 ;
    d3 = a ;
    if((d3 - d2) == (d2 - d1)) return true ;
    return false ;
}

int main(){
    for(int i = 0 ; i <= 99 ; i++){
        ans[i] = i ;
    }
    
    for(int i = 100 ; i < 1000 ; i++){
         if(decide(i)){
             ans[i] += ans[i-1] + 1 ;
         } else {
             ans[i] = ans[i-1];
         }
    }
    
    int a ; std::cin >> a ;
    std::cout << ans[a] << "\n";
    
    return 0 ;
}