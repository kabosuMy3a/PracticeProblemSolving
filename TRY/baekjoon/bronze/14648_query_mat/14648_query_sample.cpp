#include <iostream>

long long nums[1001];
long long N ; long long Q ;
long long q_type ; 
long long f1, f2, r1, r2 ;

int main(){

	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0); std::cout.tie(0x0);

	std::cin >> N ; std::cin >> Q ;
	for(long long i = 1 ; i <= N ; i++) std::cin >> nums[i];
	for(long long i = 0 ; i < Q ; i++){
		std::cin >> q_type ; 
		if(q_type == 1){
			std::cin >> f1 >> r1 ;
			long long sum = 0 ;
			for(long long j = f1 ; j <= r1 ; j++) sum += nums[j];
			long long tmp = nums[f1];
			nums[f1] = nums[r1];
			nums[r1] = tmp;
			std::cout << sum << "\n";
		} else {
			std::cin >> f1 >> r1 >> f2 >> r2 ;
			long long sum = 0 ; long long sum2 = 0;
			for(long long j = f1 ; j <= r1 ; j++){
				sum += nums[j];
			}
			for(long long j = f2 ; j <= r2 ;j++){
				sum2 += nums[j];
			}
			std::cout << sum - sum2 << "\n";
		}

	}
	return 0;
}
