#include <iostream>
#include <vector>

int N, M ;
std::vector<int> picky_cows[201]; 
int processed[201];
int cur_match[201];
int ans = 0 ;

int picky_cow_match(int cur){
	for(auto next: picky_cows[cur]){
		if(processed[next]) continue ;
		processed[next] = 1 ;

		if(cur_match[next] == 0 || picky_cow_match(cur_match[next])){
			cur_match[next] = cur ;
			return 1 ;
		}
	}
	return 0 ;
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N >> M ;
	for(int i = 1 ; i <= N ; i++){
		int c ; std::cin >> c ;
		for(int j = 0 ; j < c ; j++){
			int no ; std::cin >> no ;
			picky_cows[i].push_back(no);
		}
	}

	for(int i = 1 ; i <= M ; i++){
		processed[i] = 0 ;
		cur_match[i] = 0 ;
	}

	for(int i = 1 ; i <= N ; i++){
		for(int j = 0 ; j <= M ; j++) processed[j] = 0 ;
		if(picky_cow_match(i)) ans += 1 ; 
	}

	std::cout << ans << "\n";

	/*
	for(int i = 1 ; i <= M ; i++){
		std::cout << i << "->" << cur_match[i] << "\n";
	}*/
	return 0 ;
}