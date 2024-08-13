#include <iostream>

int main(){
	
	int N ; std::cin>> N ;
	float total = 0 ; float total_credit = 0;
	for(int i = 0 ; i < N ; i++){
		std::string s ; std::cin >> s ;
		float credit ; std::cin >> credit ;
		std::cin >> s;
		float temp = 0 ;
		if(s == "A+"){
			temp += 4.3 ;
		} else if(s == "A0"){
			temp += 4.0 ;
		} else if(s == "A-"){
			temp += 3.7 ;
		} else if(s == "B+"){
			temp += 3.3 ;
		} else if(s == "B0"){
			temp += 3.0 ;
		} else if(s == "B-"){
			temp += 2.7 ;
		} else if(s == "C+"){
			temp += 2.3 ;
		} else if(s == "C0"){
			temp += 2.0 ;
		} else if(s == "C-"){
			temp += 1.7 ;
		} else if(s == "D+"){
			temp += 1.3 ;
		} else if(s == "D0"){
			temp += 1.0 ;
		} else if(s == "D-"){
			temp += 0.7 ;
		}

		total += temp * credit ;
		total_credit += credit ;
	}

	std::cout << std::fixed ;
	std::cout.precision(2);
	std::cout << total / total_credit << "\n";

	return 0 ;
}