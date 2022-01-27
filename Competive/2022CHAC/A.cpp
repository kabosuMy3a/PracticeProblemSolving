#include <iostream>
#include <bitset>

int a, b ;

int main(){

	std::cin >> a ;
	b = ~a + 1 ;

	std::bitset<32> before = a;
	std::bitset<32> after = b ;

	std::string bs = before.to_string();
	std::string as = after.to_string();

	int ans = 0; 
	for(int i = 0 ; i < 32 ; i++) if(bs[i] != as[i]) ans++;
	
	std::cout << ans <<"\n";

	return 0 ;
}
