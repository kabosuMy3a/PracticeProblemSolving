#include <iostream>
#include <bitset>
#include <cstring>

int N ;
int work_days[15];
int pays[15];
int max_total_pay = 0 ;

int main(){
	
	std::cin >> N ;
	int brute_force = 2 ;
	for(int i = 1 ; i < N ; i++) brute_force *= 2 ;
	for(int i = 0 ; i < N ; i++) std::cin >> work_days[i] >> pays[i];

	for(int i  = 1 ; i < brute_force ; i++){
		std::bitset<16> m = i ;
		std::string mask = m.to_string();
		mask = mask.substr((16 - N), N);
		
		int cur = 0; int next = 0 ; int total_pay = 0 ;
		for(auto c : mask){
			if(c == '1'){
				if(cur < next || cur + work_days[cur] > N) break ; 
				next += work_days[cur];
				total_pay += pays[cur];
			}
			cur++ ;
			if(next < cur) next = cur ;
		}
		if(total_pay > max_total_pay){
			max_total_pay = total_pay ;
			//std::cout << mask << "\n";
		}
	}

	std::cout << max_total_pay << "\n";
	
	return 0;
}