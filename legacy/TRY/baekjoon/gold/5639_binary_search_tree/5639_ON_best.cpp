#include <iostream>
	
int nums[10001] ;
int N = 0;

void solve(int s, int e){
	if(s == e) return ;
	int left = s + 1; int right = e ;

	for(int i = left ; i < e ; i++){
		if(nums[s] < nums[i]){
			right = i ;
			break; 
		}
	}

	solve(left, right) ;
	solve(right, e);

	std::cout << nums[s] << "\n" ;
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	while(std::cin>>nums[N]){ N++; }
	solve(0, N);
	return 0 ;
}