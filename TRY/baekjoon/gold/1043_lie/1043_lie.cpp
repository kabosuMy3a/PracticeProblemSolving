#include <iostream>
#include <vector>

int party[50][50] ;
int num_people_in_party[50];

int blacklist[51] ;
std::vector<int> people_with[51]; 
int visited[51] ;


void dfs(int cur){
	if(visited[cur]) return ;
	visited[cur] = 1 ;
	for(auto next : people_with[cur]){
		dfs(next) ;
	} 
}

int main(){
    std::ios_base::sync_with_stdio(0x0);
	int ans = 0 ;
	int N, M ; std::cin >> N >> M ;
	int num_black ; std::cin >> num_black ;
	for(int i = 0 ; i < num_black ; i++) std::cin >> blacklist[i] ;
	for(int i = 0 ; i < M ; i++){
		std::cin >> num_people_in_party[i] ;
		for(int j = 0 ; j < num_people_in_party[i] ; j++) std::cin >> party[i][j] ;
		for(int j = 0 ; j < num_people_in_party[i] ; j++){
			for(int k = j + 1 ; k < num_people_in_party[i] ; k++){
				int a = party[i][j] ; int b = party[i][k] ;
				people_with[a].push_back(b);
				people_with[b].push_back(a);
			}
		}
	} 

	for(int i = 0 ; i < num_black ; i++){
		int root = blacklist[i] ;
		dfs(root);
	}

	for(int i = 0 ; i < M ; i++){
		int flag = 0 ;
		for(int j = 0 ; j < num_people_in_party[j] ; j++){
			int p = party[i][j];
			if(visited[p]){
				flag = 1 ; break ; 
			}
		}
		if(!flag) ans++ ;
	}
	std::cout << ans << "\n";
	return 0 ;
}