#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>

int N ;
std::pair<long long, long long> villages[100000];

int main(){

	std::cin >> N ; long long sum_people = 0;
	for(int i = 0 ; i < N ; i++){
		long long a, b ; std::cin >> a >> b;
		villages[i] = {a,b};
		sum_people += b ;
	}

	if(sum_people == 0){
		std::cout << -1000000000 << "\n";
		return 0; 
	}
	if(sum_people % 2 == 0) sum_people = sum_people / 2 ;
	else sum_people = sum_people / 2 + 1 ;
	std::sort(villages, villages + N);
	long long cur_people = 0 ;
	for(int i = 0; i < N ; i++){
		cur_people += villages[i].second ;
		if(cur_people >= sum_people){
			std::cout << villages[i].first << "\n"; 
			return 0;
		}
	}

	return 0; 
}