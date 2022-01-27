#include <iostream>
#include <algorithm>
#include <utility>
#include <cassert>

int main(){

    std::ios_base::sync_with_stdio(0x0);
    std::cin.tie(0x0);
	int T ; std::cin >> T ;
	for(int t = 0 ; t < T ; t++){
		long long d[3] ;
		int start_idx = -1 ; long long max_val = -1 ;
		for(int i = 0 ; i < 3 ; i++){
			std::cin >> d[i]; 
			if(max_val < d[i]){
				max_val = d[i]; 
				start_idx = i ;
			}
		}

		int l1= start_idx ; int l2 = (start_idx+1)%3 ; int l3 = (start_idx+2)%3 ;
		long long a = d[l1] ; long long b = d[l2] ; long long c = d[l3] ;

		if((a + b + c) % 2 == 1 || a > b + c){
			std::cout << -1 << "\n" ;
			continue ;
		}

		std::pair<long long, long long>	landmark[3]; 
		
		landmark[l1].first = 1 ; landmark[l1].second = 1 ;
		landmark[l2].first = 1 + a ; landmark[l2].second = 1;
		landmark[l3].second = 1 + (b + c -a)/2 ; 
		landmark[l3].first = landmark[l2].first - (b - (landmark[l3].second - 1))

		if(b <= c){
			long long max_adjust = (b+c+a)/4 - (b+c-a)/2;
			landmark[l2].first -= max_adjust ;
			landmark[l2].second  += max_adjust ;
			landmark[l3].first -= max_adjust ;
			landmark[l3].second += max_adjust ;
 		} else {
 			long long max_adjust = (b+c+a)/4 - (b+c-a)/2;
 			landmark[l1].second += max_adjust ;
 			landmark[l2].first -= max_adjust ;
 			landmark[l3].second += max_adjust ;
		}

		std::cout << landmark[0].first << " " << landmark[0].second << " ";
		std::cout << landmark[1].first << " " << landmark[1].second << " ";
		std::cout << landmark[2].first << " " << landmark[2].second << "\n";


	}

	return 0 ;
}