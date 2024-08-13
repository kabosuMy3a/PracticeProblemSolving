#include <iostream>
#include <algorithm>
int nums[50];
int main(){
    std::ios_base::sync_with_stdio(0x0);
    int N ; std::cin >> N ;
    for(int i = 0 ; i < N ; i++) std::cin >> nums[i] ;
    std::sort(nums, nums+N);
    int b ; std::cin >> b ;
    int a = 0 ; int c ;
    for(int i = 0 ; i < N ; i++){
        if(b <= nums[i]){
            c = nums[i] ;
            break ; 
        } 
        a = nums[i];
    }

    std::cout << a << " " << b << " " << c << "\n";
    if(c == b){
        std::cout << 0 << "\n";
        return 0 ;
    }
    
    int ans = 0 ;
    ans += (b - (a + 1)) * (c - b) ;
    ans += (c - (b + 1)) ;
    std::cout << ans << "\n";
    
    return 0 ;
}