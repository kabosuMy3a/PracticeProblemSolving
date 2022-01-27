#include <iostream>
#include <algorithm>

int K, N ;
long long lan_cables[10000];

int main(){

	std::ios_base::sync_with_stdio(0x0);
	std::cin >> K >>  N ;

	long long max_length = 0 ;
	for(int i = 0 ; i <  K  ; i++){
		long long a ; std::cin >> a;
		lan_cables[i] = a;
		if(a > max_length) max_length = a ;
	}
    
    std::sort(lan_cables, lan_cables+K, std::greater<int>());

	long long s = 1 ; long long e = max_length + 1;
    long long ans = 1; 
	while(1){
		long long cur_length = (s+e)/ 2;

		int have = 0 ;
		for(int i = 0 ; i < K ; i++){
			have += lan_cables[i] / cur_length ; 
            if(have >= N) break; 
		}

		if(have >= N) ans = cur_length ;
		if(cur_length == s) break ;

		if(have < N) e = cur_length;
		else s = cur_length ;

		//std::cout << cur_length << ", ";
		//std::cout << have << "\n";
	}

	std::cout << ans << "\n" ;

	return 0 ; 
}