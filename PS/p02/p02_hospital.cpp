#include <iostream>
////////////////////////
//TODO::IMPLEMENT SORT//
////////////////////////
#include <algorithm>

typedef struct {
	 long long point ;
	 long long num_people ;

} Building ; 

bool compare(Building a, Building b){
	if(a.point == b.point)
		return a.num_people < b.num_people ;

	return a.point < b.point ;
}

int main(){

	long long n ;
	long long k ;
	std::cin >> n >> k ;

	Building * buildings = new Building[n] ;

	for(int i = 0 ; i < n ; i++){
		long long np ;
		long long p ; 
		std::cin >> np >> p ;
		buildings[i].num_people = np ;
		buildings[i].point = p ;
	}

	/////////////////////////
	//TODO:: IMPLEMENT SORT//
	/////////////////////////
	std::sort(buildings, buildings + n, compare); 

	long long front_point = buildings[0].point ;
	long long tail_point = k * 2 + front_point ;

	long long buildings_index_front = 0 ;
	long long buildings_index_tail = 0 ;

	long long walkable = buildings[0].num_people ;

	while(true){
		long long p = buildings[buildings_index_tail + 1].point ;
		if(p > tail_point || buildings_index_tail + 1 == n){
			break ; 
		} else { 
			walkable += buildings[++buildings_index_tail].num_people ; 
		}
	}

	long long max_wakable = walkable ;

	while(true){
		buildings_index_tail += 1 ;
		if(buildings_index_tail >= n) break ; 

		Building * b_included = &buildings[buildings_index_tail] ; 

		walkable += b_included->num_people ;

		long long range = b_included->point - tail_point ;
		front_point += range ;
		tail_point = b_included->point ;

		while(true){
			Building * b_exclude_testing = &buildings[buildings_index_front] ;
			if(b_exclude_testing->point < front_point){
				buildings_index_front += 1; 
				walkable -= b_exclude_testing->num_people ;
			} else {
				break ;
			}
		}

		if(max_wakable < walkable) max_wakable = walkable ;

	}

	std::cout << max_wakable << std::endl; 

	delete[] buildings ;

	return 0 ;
}