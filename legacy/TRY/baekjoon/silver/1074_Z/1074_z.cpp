#include <iostream>
#include <bitset>

int main(){
	int N , r, c ; std::cin >> N >> c >> r;
	std::string r_bin = std::bitset<32>(r).to_string() ;
	std::string c_bin = std::bitset<32>(c).to_string() ;

	int ans = 0 ;  int adding_val = 1 ;
	for(auto it = r_bin.rbegin() ; it != r_bin.rend() ; it++){
		if(*it == '1') ans += (adding_val * adding_val) ;
		adding_val *= 2 ;
	}

	adding_val = 1 ;
	for(auto it = c_bin.rbegin() ; it != c_bin.rend() ; it++){
		if(*it == '1') ans += (2 * adding_val * adding_val) ;
		adding_val *= 2 ;
	}

	std::cout << ans << "\n";
	return 0 ;
}