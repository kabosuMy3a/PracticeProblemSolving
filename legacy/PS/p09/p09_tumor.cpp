
#include <iostream>
#include <vector>
#include <cstring>

int tumor_weights[451] ;
int N, B ;
int cluster_max_weight = 0 ; 

std::vector<int> tumor_adj_list[451];

int component[450]; int linked_nodes[450]; int cnt[451];
int component_sz ; int linked_nodes_sz ; 
void find_nodes_linking_all_component(){
	int max_component = 0 ;

	for(int i = 0 ; i < linked_nodes_sz ; i++)
		linked_nodes[i] = 0;
	linked_nodes_sz = 0 ;

	for(int i = 1 ; i <= N ; i++)
		cnt[i] = 0 ;

	for(int i = 0 ; i < component_sz ; i++){
		int cur = component[i];
		if(max_component > cur) max_component = cur ;
		for(auto tumor : tumor_adj_list[cur]){
			cnt[tumor] += 1;
		}
	}

	int lkn_idx = 0 ;
	for(int i = 1 ; i <= N ; i++){
		if(cnt[i] > max_component && cnt[i] == component_sz){
			linked_nodes[lkn_idx++] = i;
		}
	}
	linked_nodes_sz = lkn_idx ;

}

void generator(){

 	find_nodes_linking_all_component();

 	if(linked_nodes_sz == 0) return ;
 	int c[450] ; int c_sz = component_sz ;
 	int ln[450] ; int ln_sz = linked_nodes_sz ;

 	for(int i = 0 ; i < component_sz ; i++)
 		c[i] = component[i];
 	for(int i = 0 ; i< ln_sz ; i++)
 		ln[i] = linked_nodes[i];

 	int component_weights = 0 ; 
 	for(int i = 0 ; i < c_sz ; i++){
 		component_weights += tumor_weights[c[i]];
 	}
 	for(int i = 0 ; i < ln_sz ; i++){
 		for(int j = 0 ; j < c_sz ; j++)
 			component[j] = c[j] ;
 		component_sz = c_sz ;
 		component[component_sz++] = ln[i];
 		int cur_weights = component_weights + tumor_weights[ln[i]];
 		if(cur_weights > cluster_max_weight){
 			cluster_max_weight = cur_weights ;
 		}
 		generator();
 	}
}

int main(){
	std::cin>> N; std::cin>> B;
	for(int i = 1 ; i <= N ;i++){
		int tw ; std::cin >> tw ;
		tumor_weights[i] = tw;
	}

	for(int i = 0 ; i < B ; i++){
		int a, b;
		std::cin >> a >> b; 
		if(a > b)
			tumor_adj_list[b].push_back(a); 
		else
			tumor_adj_list[a].push_back(b);
	}

	for(int i = 1 ; i <= N ; i++){
		memset(component, 0, sizeof(component));
		component[0] = i;
		component_sz = 1;
		generator();
	}


	std::cout << cluster_max_weight << std::endl;
	return 0;
}