#include <iostream>
#include <queue>

int N ;
std::vector<int>tree[100001];
int parents[100001];

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N ;
	for(int i = 1 ; i <= N ; i++){
		int a, b ; std::cin >> a >> b;
		tree[a].push_back(b) ;
		tree[b].push_back(a) ;
		parents[i] = 0 ;
	}

	std::queue<int> bfs_q ;
	bfs_q.push(1);
	while(!bfs_q.empty()){
		int cur = bfs_q.front(); bfs_q.pop();
		for(auto next : tree[cur]){
			if(parents[next] != 0) continue ;
			parents[next] = cur; 
			bfs_q.push(next);
		}
	}

	for(int i = 2 ; i <= N ; i++){
		std::cout << parents[i] << "\n";
	}

	return 0;
}