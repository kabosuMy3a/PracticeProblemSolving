#include <iostream>
#include <vector>

std::vector<int> tree[200001] ;
int wanna_color[200001];
int visited[200001];
int N ;
int ans = 0 ; 


void dfs(int cur, int color){
	if(visited[cur]) return ;
	visited[cur] = 1 ;

	if(color != wanna_color[cur]){
		ans++ ;
		color = wanna_color[cur];
	}

	for(auto next : tree[cur]){
		dfs(next, color);
	}
}

int main(){
	
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N ; 
	for(int i = 1 ; i <= N ; i++) std::cin >> wanna_color[i] ;
	for(int i = 0 ; i < N-1 ; i++){
		int a, b ; std::cin >> a >> b ;
		tree[a].push_back(b) ;
		tree[b].push_back(a) ;
	}

	int st_color = wanna_color[1];
	if(st_color != 0) ans += 1;
	dfs(1, st_color);
	std::cout << ans << "\n";

	return 0 ;
}