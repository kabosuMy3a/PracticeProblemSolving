#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

std::vector<int> fib ;
int grundy[3000001] ;
int idx = 1;
std::bitset<31> mex ;


int main(){

	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);

	fib.push_back(1);
	fib.push_back(1);

	while(1){
		int cur = fib[idx] + fib[idx-1]; 
		if(cur > 3 * 1000000) break ;
		fib.push_back(cur);
		idx++ ;
	}

	for (int i = 1 ; i <= 3e6 ; i++) { 
		grundy[i] = 0 ;
        for(int f : fib){
        	int s = i - f ;
        	if(s < 0) break;
        	mex[grundy[s]] = 1;
        }
        // 31보다 안크므로 
        while(mex[grundy[i]]) grundy[i]++;
        mex.reset();
    }

	int N ; std::cin >> N;
	int ans = 0 ;
	for(int i = 0 ; i < N ; i++){
		int cur_rock ; std::cin >> cur_rock ;
		ans ^= grundy[cur_rock];
	}

	if(ans == 0){
		std::cout << "cubelover\n" ;
	} else{
		std::cout << "koosaga\n" ;
	}

	return 0 ;
}