#include <iostream>
#include <algorithm>

int N ;
int work_days[1500000];
int pays[1500000];
int max_pay[1500001];

int main(){
	
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++) std::cin >> work_days[i] >> pays[i];

	max_pay[N] = 0 ;
	max_pay[N-1] = (work_days[N-1] == 1) ? pays[N-1] : 0 ;
	for(int i = N - 2 ; i >= 0 ; i--){
		int next_day = work_days[i] + i ;
		if(next_day > N) max_pay[i] = max_pay[i+1];
		else {
			max_pay[i] = std::max(max_pay[i+1], max_pay[next_day] + pays[i]);
		} 
	}
	std::cout << max_pay[0] << "\n";
	
	return 0;
}