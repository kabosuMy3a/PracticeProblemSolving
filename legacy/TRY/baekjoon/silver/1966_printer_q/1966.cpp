#include <iostream> 
#include <queue>
#include <utility>

int main(){
    int T ; std::cin >> T ;
    for(int t = 0 ; t < T ; t++){
        int importance[10] = {0,};
        std::queue<std::pair<int,int>> printer_q ;
        
        int N, target ; std::cin >> N >> target ;
        for(int i = 0 ; i < N ; i++){
            int imp ; std::cin >> imp ;
            int is_target = 0;
            if(i == target) is_target = 1;
            printer_q.push({is_target,imp});
            importance[imp] += 1 ;
        }
        
        int ans = 0 ;
        
        while(1){
            std::pair<int,int> cur = printer_q.front();
            printer_q.pop();
            int is_printable = 1 ;
            for(int i = cur.second + 1 ; i <= 9 ; i++){
                if(importance[i] > 0) is_printable = 0 ;
            }
            if(is_printable){
                ans++;
                importance[cur.second] -= 1 ;
                if(cur.first){
                    std::cout << ans <<"\n";
                    break;
                }
            } else {
                printer_q.push(cur);
            }
        }
    }
    
    
    
    return 0 ;
}
