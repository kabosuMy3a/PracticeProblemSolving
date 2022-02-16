#include <iostream>
#include <vector>
#include <algorithm>

int N, M ;
int nums[8] ;
std::vector<int> v ;

int main(){
	std::cin >> N >> M ;
	for(int i = 0 ; i < N ; i++) nums[i] = i + 1 ;
	for(int i = 0 ; i < M ; i++) v.push_back(1);
	for(int i = 0 ; i < N-M ; i++) v.push_back(0);

	do{
		int i = 0;
		for(auto e : v){
		 	if(e == 1) std::cout << nums[i]<< " " ;
		 	i++;
			//std::cout << e << " ";
		}
		std::cout << "\n";
	} while(std::prev_permutation(v.begin(), v.end()));

	return 0;
}