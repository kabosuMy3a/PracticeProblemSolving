#include <iostream> 

int main(){
	int a, b ; std::cin >> a >> b ; int ans = 0 ;
	while(b > a){
		if(b % 10 == 1){
			b -= 1 ; b /= 10 ;
		} else if(b % 2 == 0){
			b /= 2 ;
		} else {
			ans = -1 ; break ; 
		}
		ans++ ;
	}
	if(b < a || ans == -1) std::cout << -1 << "\n";
	else std::cout << ans + 1 << "\n"; 
	return 0;
}