#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

std::vector<std::pair<int,int>> sales_info[11];

int main(){

	int N ; std::vector<std::pair<int,int>> drugs ;
	std::cin >> N ;
	for(int i = 1 ; i <= N ; i++){
		int a ; std::cin >> a ;
		drugs.push_back({a, i});
	}

	for(int i = 1 ; i <= N ; i++){
		int a ; std::cin >> a;
		for(int j = 1 ; j <= a ; j++){
			int b, c ; std::cin >> b >> c ;
			sales_info[i].push_back({c, b});
		}
	}

	std::sort(drugs.begin(), drugs.end());


	int minimum_cost = 1000000 ; 
	do {
		int cur_cost = 0 ; 
		int costs[11] ;
		for(auto drug : drugs){
			costs[drug.second] = drug.first ;
		}

		for(auto drug : drugs){
			cur_cost += costs[drug.second] ;
			for(auto sale : sales_info[drug.second]){
				costs[sale.second] -= sale.first ;
				if(costs[sale.second] < 1) costs[sale.second] = 1 ;
			}
		}

		if(minimum_cost > cur_cost) minimum_cost = cur_cost ;

	} while(std::next_permutation(drugs.begin(), drugs.end()));

	std::cout << minimum_cost << "\n";

	return 0 ;
}