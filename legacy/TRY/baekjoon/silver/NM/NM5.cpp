#include <iostream>
#include <vector>
#include <algorithm>

int N, M ;
int nums[8] ;
std::vector<int> v ;
std::vector<std::vector<int>> ans ;


bool cmp(std::vector<int> &a, std::vector<int> &b){
	int sz = a.size();
	for(int i = 0 ; i < sz ; i++){
		if(a[i] != b[i]) return a[i] < b[i] ;
	}
	return a[sz-1] < b[sz-1];

}

int main(){
	std::cin >> N >> M ;
	for(int i = 0 ; i < N ; i++) std::cin >> nums[i] ;
	for(int i = 0 ; i < M ; i++) v.push_back(1);
	for(int i = 0 ; i < N-M ; i++) v.push_back(0);
	std::sort(nums, nums + N);

	do{
		int i = 0; 	std::vector<int> sub_v ;
		for(auto e : v){
		 	if(e == 1) sub_v.push_back(nums[i]);
		 	i++;
		}	
		do{
			ans.push_back(sub_v);
		} while(std::next_permutation(sub_v.begin(), sub_v.end()));
	} while(std::prev_permutation(v.begin(), v.end()));

	std::sort(ans.begin(), ans.end(), cmp);

	for(auto sub_ans : ans){
		for(auto s : sub_ans){
			std::cout << s << " ";
		}
		std::cout << "\n";
	}

	return 0;
}