#include <iostream>
#include <cstring>

std::string s[20] ;
double num[20];
double sum =0 ;

int main(){
	for(int i = 0 ; i < 20 ; i++)
		std::cin >> s[i];
	for(int i = 0 ; i < 20 ; i++){
		std::cin >> num[i] ;
		sum += num[i];
	}
	
	for(int i = 0 ; i < 20 ; i++)
		std::cout << s[i] << ": " << num[i] << "\n";
	std::cout << sum/20 <<"\n";
	return 0; 
	
}
