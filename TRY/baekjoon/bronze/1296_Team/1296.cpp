#include <iostream>
#include <string>

int main(){

	std::string yeondu ; std::cin >> yeondu ;
	int N ; std::cin >> N ;

	int L = 0 ; int O = 0 ; int V = 0 ; int E = 0 ;
	for(auto c : yeondu){
		if(c == 'L') L += 1 ;
		else if(c == 'O') O += 1;
		else if (c == 'V') V += 1;
		else if (c == 'E') E += 1;
	}

	long double ans = 0 ; std::string s = "";

	for(int i = 0 ; i < N ; i++){
		std::string team ; std::cin >> team;
		int l = L ; int o = O ; int v = V ; int e = E ;
		for(auto c : team){
			if(c == 'L') L += 1 ;
			else if(c == 'O') O += 1;
			else if (c == 'V') V += 1;
			else if (c == 'E') E += 1;
		}

		long double cur = ((l+o) * (l+v) * (l+e) * (o+v) * (o+e) * (v+e)) % 100 ;

		std::cout << cur << "\n";

		if(ans == cur && s < team) continue ;
		if(ans <= cur){
			ans = cur ; s = team ;
		}
	}

	std::cout << s << "\n";


	

	return 0; 
}