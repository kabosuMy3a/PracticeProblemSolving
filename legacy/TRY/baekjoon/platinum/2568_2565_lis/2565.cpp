#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>

int N ; 
std::pair<int,int> line_pair[100000];
std::vector<int> lis ;
int pos_in_lis[100000];
int pil_max = 0; int pil_max_idx = 0;
std::vector<int> ans ;

int main(){
		
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0); std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int a, b ; std::cin >> a >> b;
		line_pair[i] = {a,b};
	}
	std::sort(line_pair, line_pair + N);
	for(int i = 0 ; i < N ; i++){
		auto it = std::lower_bound(lis.begin(), lis.end(), line_pair[i].second);
		if(it == lis.end()){
			lis.push_back(line_pair[i].second);
			it = lis.end() - 1;
		}
		else *it = line_pair[i].second ; 

		pos_in_lis[i] = std::distance(lis.begin(), it);
		if(pos_in_lis[i] > pil_max){
			pil_max = pos_in_lis[i];
			pil_max_idx = i ;
		}
	}
	std::cout << N - lis.size() << "\n";
	int cur = pil_max ;
	for(int i = N - 1 ; i >= 0 ; i--){
		if(cur < 0){
			ans.push_back(line_pair[i].first);
			continue ;
		}
		if(pos_in_lis[i] == cur){
			cur -= 1;
		} else {
			ans.push_back(line_pair[i].first);
		} 
	}
	std::sort(ans.begin(), ans.end());
	for(auto i : ans){
		std::cout << i << "\n";
	}

	return 0; 
}