#include <iostream>
#include <algorithm>
#include <set>

int N ;
int origin[1000000] ;
std::set<int> sorted_set ;
int sorted[1000000] ;

int main(){
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
	 	std::cin >> origin[i] ;
	 	sorted_set.insert(origin[i]);
	}

	int j = 0; int S = sorted_set.size();
	for(auto it : sorted_set){  
		sorted[j++] = it ; 
	}
	
	for(int i = 0 ; i < N ; i++){
		int idx = std::lower_bound(sorted, sorted + S, origin[i]) - sorted ;
		std::cout << idx << " ";
	}
	std::cout <<"\n";


	return 0 ;
}
