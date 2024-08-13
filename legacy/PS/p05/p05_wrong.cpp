#include <iostream>
#include <algorithm>
#include <vector>

int distance[100000] = {0} ;
int N; int K ;

int get_min(int * idx){
	int min = 2000000000;
	for(int i = 0 ; i < N-1 ; i++){
		int cur = distance[i] ;
		if(cur == 0)
			continue;
		if(min > cur){
			min = cur ;
			*idx = i ;
		}
	}
	return min ;
}

int main(){

	std::cin >> N ; std::cin >> K ;
	std::vector<int> poles ;
	for(int i = 0 ; i < N  ; i++){
		int pole ;
		scanf("%d", &pole);
		poles.push_back(pole);
	}

	std::sort(poles.begin(), poles.end());

	for(int i = 0 ; i < N-1  ; i++){
		distance[i] = poles[i+1] - poles[i] ;
	}

	int distance_size = N-1 ;
	
	while(true){
		if(distance_size + 1 == K) 
			break;
		
		int min_idx ;
		int m = get_min(&min_idx);
		
		distance[min_idx] = 0 ;	

		// 0인 애들 때문에 

		distance_size -= 1 ;

		for(int i = 0 ; i < N-1 ; i++){
			std::cout << distance[i] << " ";
		}
		std::cout << std::endl;
	}

	int a;
	std::cout << get_min(&a) << std::endl;

	return 0 ;
}