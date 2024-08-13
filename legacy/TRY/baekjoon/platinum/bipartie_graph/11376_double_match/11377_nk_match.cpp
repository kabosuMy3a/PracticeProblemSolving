#include <iostream>
#include <vector>

int N, M, K;
std::vector<int> picky_cows[2001]; 
int processed[2001];
int cur_match[1001];
int ans = 0 ;

int picky_cow_match(int cur){
    if(processed[cur]) return 0 ;
    processed[cur] = 1 ;
	for(auto next: picky_cows[cur]){
		if(cur_match[next] == 0 || picky_cow_match(cur_match[next])){
			cur_match[next] = cur ;
			return 1 ;
		}
	}
	return 0 ;
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N >> M >> K ;
	for(int i = 1 ; i <= N ; i++){
		int c ; std::cin >> c ;
		for(int j = 0 ; j < c ; j++){
			int no ; std::cin >> no ;
			picky_cows[i].push_back(no);
			picky_cows[i+N].push_back(no);
		}	
	}

	for(int i = 1 ; i <= M ; i++){
		cur_match[i] = 0 ;
	}

	int cnt = 0 ;
	for(int i = 1 ; i <= N * 2 ; i++){
		for(int j = 0 ; j <= N * 2 ; j++) processed[j] = 0 ;
		int rst = picky_cow_match(i);
		if(rst) ans += 1 ; 
		if(rst && i > N) cnt++ ;
		if(cnt == K) break; 
	}
     
	std::cout << ans << "\n";

	/*
	for(int i = 1 ; i <= M ; i++){
		std::cout << i << "->" << cur_match[i] << "\n";
	}*/
	return 0 ;
}