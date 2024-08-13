#include <iostream> 

int main(){
    
    int a ; std::cin >> a ;
    for(int j = 0 ; j < a ; j++){
        int div = 10 ;
        int sum = 0 ;
        int i = j ;
        while(i > 0){
            int digit = i % div ;
            sum += digit ;
            sum += digit / (div/10) ;
            i -= digit ;
            div *= 10 ;
        }

        if(sum == a) {
            std::cout << j << "\n";
            exit(0);
        } 
    }
    std::cout << 0 << "\n";
    
    return 0 ; 
}