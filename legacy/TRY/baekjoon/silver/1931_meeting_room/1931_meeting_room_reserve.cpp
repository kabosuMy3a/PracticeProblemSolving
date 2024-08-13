#include <iostream>
#include <utility>

int main(){
	
	int N ; std::cin >> N ;
	std::pair<int, int> meetings[100000];
	for(int i = 0 ; i < N ; i++){
		int s, e ; std::cin >> s >> e ; 
		meetings[i] = {e, s};
	}
	std::sort(meetings, meetings + N);
	int cur = meetings[0].first ;
	int ans = 1 ;
	for(int i = 1 ; i < N ; i++){
		if(meetings[i].second <= cur){
			cur = meetings[i].first;
			ans += 1; 
		}
	}
	std::cout << ans << "\n";
	return 0 ;
}

031-560-1961 1962