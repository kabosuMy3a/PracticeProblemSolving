#include <iostream>
#include <string>

std::string lines ;
long long N ;
long long ans = 0 ;

int main(){
	
	std::cin >> N >> lines ;

	for(int i = 0 ; i < N ; i++){
		int j = i ;
		int G = 0 ; int H = 0 ;
		while(true){
			if(j >= N) break ;
			if(lines.at(j) == 'G') G += 1;
			if(lines.at(j) == 'H') H += 1;
			if(j >= i+2){
				if(G == 1 || H == 1) ans += 1;
				if(G > 1 && H > 1) break ; 
			}
			j++;
			//std::cout << j << "| " << G << ", " << H  << std::endl;
		}
	}

	std::cout << ans <<std::endl;
	return 0;
}