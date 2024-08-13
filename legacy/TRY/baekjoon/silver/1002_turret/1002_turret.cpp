#include <cmath>
#include <iostream>
#include <cstdlib>

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0); std::cout.tie(0x0);
	int T ; std::cin >> T;
	for(int i = 0 ; i < T ; i++){
		int a, b, r1 ; std::cin >> a >> b >> r1;
		int c, d, r2 ; std::cin >> c >> d >> r2;

		long long x_dist = a - c; 
		long long y_dist = b - d;
		long long dist = (x_dist * x_dist) + (y_dist * y_dist);

		long long r_sum = (r1 + r2) * (r1 + r2) ;
		long long r_diff = (r1 - r2) * (r1 -r2) ;	

		if(dist == 0){
			if(r1 == r2) std::cout << -1 << "\n";
			else std::cout << 0 << "\n";
		} else{
			if(r_diff < dist && dist < r_sum){
				std::cout << 2 << "\n";
			} else if(dist == r_diff || dist == r_sum){
				std::cout << 1 << "\n";
			} else{
				std::cout << 0 << "\n";
			}
		}

	}

	return 0;
}