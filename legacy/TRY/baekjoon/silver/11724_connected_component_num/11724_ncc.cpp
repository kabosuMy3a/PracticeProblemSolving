#include <iostream>
#include <vector>
#include <queue>


std::vector<int> graph[1001];
int visited[1001];
int ans = 0;

int main(){
    std::ios_base::sync_with_stdio(0x0);
    std::cin.tie(0x0);
    
    int N, M ; std::cin >> N >> M ;
    if(M == 0){
        std::cout << 0 << "\n";
        return 0 ; 
    }
    
    for(int i = 1 ; i <= M ; i++){
        int a, b; std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i = 1 ; i <= N ; i++){
        auto sz = graph[i].size();
        if(sz == 0) visited[i] = -1;
        else visited[i] = 0 ;
    }
    
    std::queue<int> bfs_q; 
    for(int i = 1 ; i <= N ; i++){
        if(visited[i] == 0){
         bfs_q.push(i);
         visited[i] = 1 ;
        }
        else continue ;
        
        while(!bfs_q.empty()){
           int cur = bfs_q.front();
           bfs_q.pop();
           for(auto next : graph[cur]){
           	 if(visited[next] == 0){
                 bfs_q.push(next);
                 visited[next] = 1 ;
             }
           } 
        }
        
        ans+= 1;
    }
    
    std::cout << ans << "\n";
    return 0; 
}