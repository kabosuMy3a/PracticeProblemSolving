#include <iostream>

int N, M ; 
int money_need[100000];

int check(int k){
	int cur = k ;
	int num_withdraw = 1 ;
	for(int i = 0 ; i < N ; i++){
		if(cur - money_need[i] < 0){
			if(k - money_need[i] < 0) return 0 ;
			cur = k ;
			num_withdraw += 1;
		}
		cur -= money_need[i];
	}
	if(num_withdraw <= M) return 1; 
	return 0 ;
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N >> M;
	for(int i = 0 ; i < N ; i++) std::cin >> money_need[i];

	int l = 1 ; int r = 1000000001; int ans ;
	while(true){
		int m = (l + r)/2	;
		int isPass = check(m);
		if(isPass) ans = m ;
		if(l == m) break;
		if(isPass) r = m; 
		else l = m;
	}

	std::cout << ans << "\n" ;
	return 0;
}