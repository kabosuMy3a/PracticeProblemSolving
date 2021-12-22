#include <iostream>
#include <algorithm>
#include <list>

int sorted_arr[100000];

int main(){

	int N ; std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int a ; std::cin >> a ;
		std::lower_bound(sorted_arr, sorted_arr + i, a) - sorted_arr ;
		
	}

	return 0 ;
}