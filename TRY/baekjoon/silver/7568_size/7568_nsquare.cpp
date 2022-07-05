#include <iostream>
#include <utility>

std::pair<int,int> people[50] ;
int num_bigger[50] = {0,}; 
int rank[50] ;

int main(){
	int N ; std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int a, b ; std::cin >> a >> b;
		people[i] = {a,b};
	}
	for(int i = 0 ; i < N ; i++){
		std::pair<int,int> cur = people[i] ;
		int bigger = 0 ; 
		for(int j = 0 ; j < N ; j++){
			if(i == j) continue ;
			std::pair<int,int> other = people[j];
			if(cur.first < other.first && cur.second < other.second) num_bigger[i] += 1 ;
		};
	}
	for(int i = 0 ; i < N ; i++){
		std::cout << num_bigger[i] + 1 <<" ";
	}



}