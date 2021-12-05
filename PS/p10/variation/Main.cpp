#include <iostream>
#include <vector>
#include <utility>

int N ; int M ;
std::vector<std::pair<int, int>> airworks[100001];
int visited[100001] = {0};

int max_weight = 0 ;
std::vector<int> paths[100000] ;
int pw[100000] ;
int path_num = 0 ;

std::vector<int> path ;
void dfs(int weight, int id){
	//if(visited[id] == 1) return ;
	
	visited[id] = 1 ;
	path.push_back(id);
	
	if((int)airworks[id].size() == 0){
		if(weight >= max_weight){
			max_weight = weight ;
			for(auto pn : path){
				paths[path_num].push_back(pn);
			}
			pw[path_num++] = weight;
		}
	}
	
	for(auto a : airworks[id]){
		visited[a.first] = 1;
		int next_weight = weight + a.second ;
		dfs(next_weight, a.first);
	}
	
	path.pop_back();
		
}

int main() {
	std::cin >> N ; 
	std::cin >> M ;
	
	for(int i = 0 ; i < M ; i++){
		int a, b, w ;
		std::cin >> a ;
		std::cin >> b ;
		std::cin >> w ;
		airworks[a].push_back(std::make_pair(b,w));
	}	
	
	/*
	for(int i = 1 ; i <= N ; i++){
		std::cout << i << "| ";
		for(auto a : airworks[i]){
			std::cout << a.first <<", " << a.second  << " ";
		}
		std::cout << "\n";
	}*/
	

  for(int i = 1 ; i <= N ; i++){
		if(visited[i] != 1) dfs(0, i);
  }

  
	
	std::pair<int,int> ans_path[100000] ;	
	int ans = 0 ;
	
	for(int i = 0 ; i < path_num ; i++){
	  if(pw[i] == max_weight){
			for(int j = 1 ; j < (int)paths[i].size(); j++){
				std::pair<int,int> tmp = std::make_pair(paths[i][j-1], paths[i][j]);
				
				int flag = 1;
				for(int k = 0 ; k < ans ; k++){
					if(ans_path[k] == tmp){
						flag =0;
						break;
					}
				}
				if(flag) ans_path[ans++] = tmp ;
			}
		}
	}
	
	
	std::cout << max_weight << std::endl;
	std::cout << ans << std::endl;
	
	return 0;
}