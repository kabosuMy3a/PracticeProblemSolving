#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int N ; int nums[500000];
double sum = 0 ;
int val[8005] = {0} ;
int min_val = 8001 ;
int max_val = -8001 ;

bool cmp(int a, int b){
	return a > b ;
}

int main(){
	
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);

	std::cin >> N ;
	for(int i = 0 ; i < N ; i++ ){
		int a ; std::cin >> a;
		nums[i] = a;
		val[a + 4000] += 1;
		if(min_val > a) min_val = a;
		if(max_val < a) max_val = a;
		sum += a ;
	}

	std::sort(nums, nums + N);

	double tmp = sum / N;

	std::cout << round(tmp) << "\n";
	std::cout << nums[(0+N)/2] << "\n";

	int most_val = 0 ;
	for(int i = -4000 ; i <= 4000 ; i++){
		if(most_val < val[i+4000]){
			most_val = val[i+4000];
		}
	}

	std::vector<int> vec_most_vals ;
	for(int i = -4000 ; i <= 4000 ; i++){
		if(val[i+4000] == most_val) vec_most_vals.push_back(i);
	}
	std::sort(vec_most_vals.begin(), vec_most_vals.end());
	if(vec_most_vals.size() >= 2){
		std::cout << vec_most_vals[1] << "\n";
	} else{
		std::cout << vec_most_vals[0] << "\n";
	}


	int rng = max_val - min_val ;
	if(rng < 0 ) rng *= -1 ;
	std::cout << rng << "\n";



	return 0 ;
}