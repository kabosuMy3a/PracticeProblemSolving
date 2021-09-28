#include <iostream>
#include <vector> 
#include <climits>

typedef struct {

	int d_from_first ;
	int d_from_second ;
	int d_from_N ;

} NavigationInfo ;



std::ostream& operator<<(std::ostream &o, const NavigationInfo ni){
    return o  << ni.d_from_first << ", " << ni.d_from_second << ", " << ni.d_from_N ;
}


NavigationInfo navigation_info[40001] ; 
std::vector<int> graph[40001] ;


void print_navigation_info(int N){
	for(int i = 1 ; i < N+1  ; i++){
		std::cout << navigation_info[i] << std::endl; 
	}
}

void print_graph(int N){
	for(int i = 1 ; i < N+1 ; i++){
		int size = graph[i].size();
		for(int j = 0 ; j < size ; j++)
			std::cout << i << " -> " << graph[i][j] << " ";
		std::cout << std::endl; 
	}
}

int get_depth(int start, int N, int city_id){
	int d = -1 ;

	if(start == 1)
		d = navigation_info[city_id].d_from_first ;
	if(start == 2)
		d = navigation_info[city_id].d_from_second ;
	if(start == N)
		d = navigation_info[city_id].d_from_N ;

	return d; 
}

void set_depth(int start, int N, int city_id, int d){
	if(start == 1)
		navigation_info[city_id].d_from_first = d ;
	if(start == 2)
		navigation_info[city_id].d_from_second = d ;
	if(start == N)
		navigation_info[city_id].d_from_N = d;
}

void traverse_all_node(int start, int N){
	int traverse_queue[40000] ;
	int head = 0 ;
	int tail = 0 ;
	traverse_queue[tail++] = start ; 

	int visited[40001] = {0} ;
	visited[start] = 1 ;

	while(head != tail){
		int city_id = traverse_queue[head++] ;
		int edge_num = graph[city_id].size();
		int depth = get_depth(start, N, city_id);

		for(int i = 0 ; i < edge_num ; i++){
			int adj_city_id = graph[city_id][i] ;
			if(visited[adj_city_id] != 1){
				set_depth(start, N, adj_city_id, depth+1);
				traverse_queue[tail++] = adj_city_id ; 
				visited[adj_city_id] = 1; 
			}
		}
	}

}

void note(int N){
	traverse_all_node(1, N);
	traverse_all_node(2, N);
	traverse_all_node(N, N);
}

long long calculate(int P, int Q, int R, int N){
	long long min_fuel = LLONG_MAX ;

	for(int i = 1 ; i < N+1 ; i++){
		NavigationInfo city = navigation_info[i] ;
		if(city.d_from_first == -1 || city.d_from_second == -1 || city.d_from_N == -1)
			continue ;
		long long fuel = 0 ;
		fuel += P * city.d_from_first ;
		fuel += Q * city.d_from_second ;
		fuel += R * city.d_from_N ;
		if(fuel < min_fuel) 
			min_fuel = fuel ;
	}
	return min_fuel ;
}

int main(){

	int P ; int Q ; int R ;
	int N ; int M ;
	std::cin >> P >> Q >> R >> N >> M ;

	for(int i = 1 ; i < N+1 ; i++){
		NavigationInfo ni = {-1, -1, -1} ;

		if(i == 1)
			ni.d_from_first = 0 ;
		if(i == 2)
			ni.d_from_second = 0 ;
		if(i == N)
			ni.d_from_N = 0 ;
					
		navigation_info[i] = ni ;
 	}

	for(int i = 0 ; i < M ; i++){
		int a ; int b ;
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	note(N);
	long long min_fuel = calculate(P, Q, R, N);
	std::cout << min_fuel << std::endl ;

	return 0 ;
}