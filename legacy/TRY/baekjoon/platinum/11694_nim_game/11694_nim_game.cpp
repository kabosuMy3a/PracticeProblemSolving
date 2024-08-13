#include <iostream> 

int N ;
int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N ; long long ans ;
	for(int i = 0 ; i < N ; i++){		
			long long a ; std::cin >> a;
			if(i == 0) ans = a ;
			else ans ^= a ;
	}
	if(ans == 0){
		std::cout << "cubelover" << "\n";
	} else {
		std::cout << "koosaga" << "\n";
	}

	return 0 ;
}