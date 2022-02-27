#include <iostream> 

 int main(){
    int N ; std::cin >> N ; int cur = 0 ;
    int first = 0 ; int second = 0 ;
    for(int i = 1 ; i <= 1000000000 ; i++){
        if(cur + i >= N ){
            if(i % 2 == 0){
                first = i - ((cur + i) - N) ;
                second = (cur + i) - N + 1 ;
                 
            } else {
                first = (cur + i) - N + 1 ;
                second = i - ((cur + i) - N) ; 
            }
            break;
        } else {
            cur += i ;
        }
    }
    
    std::cout << first << "/" << second << "\n";
    
    return 0 ;
}