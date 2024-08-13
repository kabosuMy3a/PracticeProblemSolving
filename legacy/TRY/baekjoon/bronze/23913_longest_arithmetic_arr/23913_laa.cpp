#include <iostream>

int T, N ;
int arr[200000];
int num_cur_subsq ;
int cur_diff ;

int main(){
    std::ios_base::sync_with_stdio(0x0);
    std::cin.tie(0x0); std::cout.tie(0x0);
   
    std::cin >> T ; 
    for(int t = 1 ; t <= T ; t++){
        std::cin >> N ;
        for(int i = 0 ; i < N ; i++) std::cin >> arr[i];
        
        int ans = 1;
        for(int i = 0 ; i < N -1 ; i++){
            int cur = arr[i]; int next = arr[i+1];
            if(i == 0){
                cur_diff = next - cur ;
                num_cur_subsq = 1;
            } else {
                if(cur_diff != next - cur){
                    num_cur_subsq = 1 ;
                    cur_diff = next - cur ;
                } else {
                    num_cur_subsq += 1;
                }
            }
            if(num_cur_subsq > ans) ans = num_cur_subsq ;
        }
       
        std::cout << "Case #" << t <<": " << ans + 1 << "\n";
    }
    
    return 0;
}