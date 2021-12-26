#include <iostream>
#include <algorithm>
    
int N ; int Q ;
int nums[100000];
int needle ;

int main(){
    std::ios_base::sync_with_stdio(0x0);
    std::cout.tie(0x0) ; std::cin.tie(0x0);
    
    std::cin >> N ;
    for(int i = 0 ; i < N ; i++){
        std::cin >> nums[i];
    }
    std::cin >> Q;
    std::sort(nums, nums + N);
    for(int i = 0 ; i < Q ; i++){
        std::cin >> needle ;
        int s = 0 ; int e = N ;
        int is_find = 0 ;
        while(42){
            int mid = (s+e)/2;
            if(nums[mid] == needle){
                is_find = 1;
                break; 
            }
            if(mid == s) break; 
            if(nums[mid] < needle){
                s = mid;
            } else {
                e = mid;
            }
        }
        if(is_find) std::cout << 1 << "\n";
        else std::cout << 0 << "\n";
    }
    
    return 0 ;
}