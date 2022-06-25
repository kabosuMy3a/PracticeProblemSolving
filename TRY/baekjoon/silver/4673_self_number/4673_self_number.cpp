#include <iostream>

int nums[10001] = {0,};

int main(){
    for(int i = 1 ; i <= 10000 ; i++){
        if(nums[i] == 1) continue; 
        int a = i ;
        while(1){
           int b = a ;
           for(int j = 10000 ; j >= 1 ; j /= 10){
               b += (a/j);
               a %= j ;
           }
           a = b ;
           if(a > 10000 || nums[a] == 1) break;
           nums[a] = 1;
        }
    }
    for(int i = 1 ; i <= 10000 ; i++){
        if(nums[i] == 0) std::cout << i << "\n";
    }
    return 0 ;
}