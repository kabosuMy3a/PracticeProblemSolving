#include <iostream>
#include <unordered_map>

int main(){
	
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);

	std::unordered_map<int, int> um ;
	int N, M ;
	std::cin >> N  ;
	for(int i = 0 ; i < N ; i++){
		int a ; std::cin >> a;
		auto s = um.find(a);
		if(s != um.end()){
			um[a] += 1;
		} else {
			um.insert({a,1});
		}
	}
	std::cin >> M ;
	for(int i = 0 ; i < M ; i++){
		int a ; std::cin >> a;
		auto s = um.find(a) ;
		if(s != um.end()){
			std::cout << um[a] << " ";
		} else {
			std::cout << 0 << " ";
		}
	}
	std::cout << "\n";

	return 0;
}