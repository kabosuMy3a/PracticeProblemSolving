#include <iostream>
#include <utility>
#include <algorithm>

std::pair<int, std::pair<int,int>> people[50];
int rank[50];
bool cmp(std::pair<int, std::pair<int,int>> a , std::pair<int,std::pair<int,int>> b){
	if(a.second.first > b.second.first && a.second.second > b.second.second) return true ;
	return false;
}

int main(){
	
	int N ; std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int a, b ; std::cin >> a >> b;
		people[i] = {i,{a,b}};

	}
	std::sort(people, people+N, cmp);
	rank[people[0].first] = 1; 
	int cur_rank = 1; int num_same_rank = 1 ; 
	for(int i = 1; i < N; i++){
		std::pair<int,int> prev = people[i-1].second ;
		std::pair<int,int> cur = people[i].second ;
		if(prev.first > cur.first && prev.second > cur.second){
			cur_rank++ ;
			rank[people[i].first] = cur_rank + num_same_rank - 1;
			num_same_rank = 1;

		} else {
			rank[people[i].first] = cur_rank ;
			num_same_rank++ ;
		}
		
	}

	for(int i = 0 ; i < N ; i++){
		std::cout << rank[i] << " " ;
	}

	return 0 ;
}