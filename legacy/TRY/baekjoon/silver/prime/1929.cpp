#include <iostream> 
int nums[1000001] ;
int s ; int e ;

int main(){
    std::ios_base::sync_with_stdio(0x0);
    std::cout.tie(0x0);
    
    std::cin >> s >> e ;
    for(int i = 0 ; i <= e ; i++){
        nums[i] += 1 ;
    }

    for(int i = 2 ; i <= 1000 ; i++){
        if(nums[i] == 0) continue ;
        int j = 1 ;
        while(i * j <= e){
            if(j != 1){
                nums[i * j] = 0 ;
            }
            j++; 
        }
    }
    for(int i = s ; i <= e ; i++){
        if(nums[i]) std::cout << i  << "\n";
    }

    return 0 ;
}
