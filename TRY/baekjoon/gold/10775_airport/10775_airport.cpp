#include <iostream>

int gate_head[100001] ;
int ans = 0 ;

int find_empty_gate(int gate){
	if(gate_head[gate] == 0){
		std::cout << ans << "\n";
		exit(0);
	}

	if(gate_head[gate] == gate){
		gate_head[gate] -= 1 ;
		return gate_head[gate] ;
	} else{ 
		return gate_head[gate] = find_empty_gate(gate_head[gate]) ;
	}
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	int G, P ; std::cin >> G >> P ;
	for(int i = 1 ; i <= G ; i++) gate_head[i] = i ;
	for(int i = 0 ; i < P ; i++){
		int gate ; std::cin >> gate ;
		find_empty_gate(gate);
		ans++ ;
	}
	std::cout << ans << "\n";
	return 0; 
}