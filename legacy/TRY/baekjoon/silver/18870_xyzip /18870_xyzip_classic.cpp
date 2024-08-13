#include <iostream>
#include <utility>
#include <algorithm>

std::pair<int, int> value_index[1000000];
int res[1000000];
int N ;

int main(){

	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0); std::cout.tie(0x0);
	std::cin >> N;

	for(int i = 0 ; i < N ; i++){
		int a ; std::cin >> a;
		value_index[i] = {a,i};
	}

	std::sort(value_index, value_index + N);

	res[value_index[0].second] = 0;
	for(int i = 1 ; i < N ; i++){
		if(value_index[i].first == value_index[i-1].first){
			res[value_index[i].second] = res[value_index[i-1].second];
		} else {
			res[value_index[i].second] = res[value_index[i-1].second] + 1 ;
		}
	}

	for(int i = 0 ; i < N ; i++){
		std::cout << res[i] << " ";
	}
	std::cout << "\n";

	return 0;
}