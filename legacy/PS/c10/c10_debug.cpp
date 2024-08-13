#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int N ;
std::pair<int, int> buildings[50000] ;

std::vector<std::pair<int, int>> chains[50000] ;
std::vector<int> chains_coloring[50000];
#define RED 0 
#define BLACK 1 
int num_chains ;

bool is_constructible(std::pair<int, int> l_b, std::pair<int, int> r_b){
	int x_dist = r_b.first - l_b.first ;
	int y_dist = r_b.second -l_b.second ;	
	return (x_dist * x_dist + y_dist * y_dist) <= 25 ;
}

bool cmp_all_buildings_in_chains(std::pair<int, int> cur, int chain_idx, int * where, int * color){
	for(int i = 0 ; i < chains[chain_idx].size() ; i++){
		std::pair<int, int> prev = chains[chain_idx][i];
		if(is_constructible(prev, cur)){
			*where = i ;
			*color = chains_coloring[chain_idx][i] ^ 1 ;
			return true ; 
		}
	}
	return false ;
}

int main(){

	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int x, y;
		std::cin >> x >> y;
		buildings[i] = std::make_pair(x, y);
	}
	std::sort(buildings, buildings + N) ;

	chains[0].push_back(buildings[0]);
	chains_coloring[0].push_back(RED);
	num_chains = 1;

	for(int i = 1 ; i < N ; i++){
		std::pair<int, int> cur = buildings[i] ; 
		int first_find_idx = -1 ; int is_added = 0;
		for(int j = 0 ; j < num_chains ; j++){
			int cur_color ; int where ;
			if(cmp_all_buildings_in_chains(cur, j, &where, &cur_color)){
				if(first_find_idx == -1){
					chains[j].push_back(cur);
					chains_coloring[j].push_back(cur_color);	
					first_find_idx = j ;
					is_added = 1 ;
				}

				else {
					int where_color = chains_coloring[j][where] ;
					for(int k = 0 ; k < chains[j].size() ; k++){
						chains[first_find_idx].push_back(chains[j][k]);
						if(where_color == cur_color)
							chains_coloring[j][k] ^= 1;

						chains_coloring[first_find_idx].push_back(chains_coloring[j][k]);
					}
					chains[j].clear();
					chains_coloring[j].clear();
				}
			} 
		}
		if(!is_added){
				chains[num_chains].push_back(cur);
				chains_coloring[num_chains++].push_back(RED);
		}	
	}
	
	int pizza = 0 ;
	for(int i = 0 ; i < num_chains ; i++){
		int num_red = 0; int num_black = 0;
		for(int j = 0 ; j < chains[i].size() ; j++){
			if(chains_coloring[i][j] == RED) num_red += 1;
			else num_black += 1;
		}
		pizza += std::min(num_red, num_black);
	}

	std::cout << pizza << std::endl;

	
	for(int i = 0 ; i < num_chains ; i++){
		for(int j = 0 ; j < chains[i].size() ; j++){
			std::cout << "(" << chains[i][j].first << ", " << chains[i][j].second << ", "
			<< chains_coloring[i][j] << ") " ;
		}
		std::cout << "\n";
	}
	

	return 0 ; 
}