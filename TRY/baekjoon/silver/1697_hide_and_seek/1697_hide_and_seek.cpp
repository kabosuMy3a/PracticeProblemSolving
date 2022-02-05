#include <iostream>

int JOHN, COW ;
int catch_time[100001];

int main(){

	std::cin >> JOHN >> COW ;

	if(COW <= JOHN){
		std::cout << JOHN - COW << "\n";
		return 0 ;
	}

	for(int i = 1 ; i <= 100000 ; i++) catch_time[i] = 0 ;
	
	int cur ; int prev = COW ;
	while(prev > 1){
		cur = prev / 2 ;
		if(prev % 2 == 0){
			catch_time[cur] = catch_time[prev] + 1 ;
			int half = (prev + cur)/2 ;
			for(int i = half ; i < prev ; i++) catch_time[i] = catch_time[prev] + prev - i ;
			for(int i = cur + 1 ; i < half ; i++) catch_time[i] = catch_time[cur] + i - cur ;
		}  else {
			catch_time[cur] = catch_time[prev] + 2 ;
			catch_time[cur+1] = catch_time[prev] + 2 ;
			int other = (cur+1) * 2 ;
			if(other <= prev && catch_time[other] + 1 < catch_time[cur+1] ) catch_time[cur+1] = catch_time[other] + 1;
			int half = (prev + cur)/2 ;
			for(int i = half ; i < prev ; i++) catch_time[i] = catch_time[prev] + prev - i ;
			for(int i = cur + 2 ; i < half ; i++) catch_time[i] = catch_time[cur+1] + i - (cur + 1);

		}
		prev = cur ;
	}

	catch_time[0] = catch_time[1] + 1;
	for(int i = 0 ; i <= COW ; i++){
		std::cout << catch_time[i] << " ";
	}
	std::cout << "\n";
	std::cout << catch_time[JOHN] << "\n" ;
	return 0 ;
}