
#include <iostream>

int tumor_weights[451] ;
int N, B ;
int cluster_max_weight = 0 ; 

int main(){
	std::cin>> N; std::cin>> B;
	for(int i = 1 ; i <= N ;i++){
		int tw ; std::cin >> tw ;
		tumor_weights[i] = tw;
		std::cout << tumor_weights[i] << "\n";
	}

	for(int i = 0 ; i < B ; i++){
		int a, b;
		std::cin >> a >> b; 
		std::cout << a << ", "<< b << "\n" ;
	}

	std::cout << cluster_max_weight << std::endl;
	return 0;
}