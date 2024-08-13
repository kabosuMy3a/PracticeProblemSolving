#include <iostream>
#include <vector>

int N ;
typedef struct {
	int size ;
	int speed ;
	int inteligence ;
} Shark; 

int compare(Shark a, Shark b){
	if(a.size == b.size && a.speed == b.speed && a.inteligence == b.inteligence){
		return 1 ;
	}
	if(a.size >= b.size && a.speed >= b.speed && a.inteligence >= b.inteligence){
		return 2 ;
	}

	if(b.size >= a.size && b.speed >= a.speed && b.inteligence >= a.inteligence){
		return -1 ;
	}

	return 0 ;
}


Shark sharks_info[50] ;
std::vector<int> sharks_graph[50]; 


int main(){
	
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int a, b, c; std::cin >> a >> b >> c;
		sharks_info[i] = {a,b,c};
		for(int j = 0 ; j < i ; j++){
			int cmp = compare(sharks_info[i], sharks_info[j]);
			if(cmp == 1 || cmp == -1) sharks_graph[j].push_back(i) ;
			if(cmp == 1 || cmp == 2) sharks_graph[i].push_back(j) ;
		}
	}

	for(int i = 0 ; i < N ; i++){
		std::cout << i << " -> " ;
		for(auto cur : sharks_graph[i]){
			std::cout << cur << " " ; 
		}
		std::cout << "\n";
	}

	return 0 ;
}