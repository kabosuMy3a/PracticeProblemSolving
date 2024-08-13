#include <iostream>
#include <algorithm>

int robots[1000001];
int ss[2000002];
int N, R, M;

int main(){

    std::ios_base::sync_with_stdio(0x0);
	std::cin >> N >> R >> M ;

	for(int i = 0 ; i < N ; i++){
        std::cin >> robots[i] ;
    }
    std::sort(robots, robots+N);
	robots[N] = robots[0] + M ;
    
    for(int i = 0 ; i < N ; i++){
        ss[i] = robots[i+1] - robots[i] - (R * 2); 
        ss[i+N] = ss[i];
    }

	int ans = 0 ; int need_to_move = 0;
	for(int i = 0 ; i < (2 * N) - 1 ; i++){
		int dist = ss[i];
	    need_to_move += dist ;
        if(need_to_move < 0) need_to_move = 0 ; 
        if(ans < need_to_move) ans = need_to_move ;
	}

	std::cout << (ans+1) /2 << "\n";

	return 0;
}
