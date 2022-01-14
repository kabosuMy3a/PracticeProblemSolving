#include <iostream>
#include <cmath>


int calculated[50001] = {0,};

int cal(int n){
    if(calculated[n] != 123123123) return calculated[n] ;

    for(int i = (int)sqrt(n) ; i >= 1 ; i--){
        if(n - (i * i) == 0){
            calculated[n] = 1 ;
            return 1 ;
        }
        int a = cal(n - (i * i)) + 1;
        if(calculated[n] > a) calculated[n] = a ; 
    }
    return calculated[n];
}

int main(){
    int n ; std::cin >> n;
    for(int i = 1 ; i <= 50000 ; i++){
        calculated[i] = 123123123 ;
    }
    cal(n);
    std::cout << calculated[n] << "\n";
    return 0;
}