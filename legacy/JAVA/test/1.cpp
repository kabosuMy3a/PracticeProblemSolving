#include <iostream>

int arr[14];
int nums[256];

int main(){

	int N ; std::cin >> N;
	for(int i = 0 ; i < N ; i++){
		std::cin >> arr[i] ;
		std::cout << arr[i] << "\n";
	}

	for(int i = 0 ; i < N ; i++){
		nums[arr[i]] += 1; 
	}

     int cur = 0; int min_diff = 10000 ; int min_diff_idx = 0 ;
     for(int i = 0 ; i < 256 ; i++){
        int diff = N - cur ;
        if(abs(cur -diff) < min_diff){
            min_diff = abs(cur-diff) ;
            min_diff_idx = i ;
        }
        cur += nums[i] ;
     }
     std::cout << min_diff_idx << "\n";

	return 0 ;
}