#include <iostream>

typedef struct {

	int front_max ;

	int next_max ;

	int altitude ;

} Point ;

int is_not_explored(Point * point);

void modelingMountain(Point ** &mountain, const int N );
void deleteMountain(Point ** &mountain, const int N);

void start(Point ** &mountain, const int N);
void explore(Point ** &mountain, const int N, int x , int y);
int make_path(Point ** &mountain, const int N, int x, int y, int from);

int max_diff = 0 ;

int main(){

	int n;
	std::cin >> n ; 
	const int N  = n ;

	Point ** mountain = new Point * [N] ;
	modelingMountain(mountain, N) ;
	start(mountain, N);
	deleteMountain(mountain, N) ; 

	return 0 ; 
}


void modelingMountain(Point ** &mountain, const int N ){
	for(int i =  0 ; i < N ; i++){
		Point * prow = new Point [N] ;
		mountain[i] = prow ; 
		for(int j = 0 ; j < N ; j++){
			int a ; 
			std::cin >> a ;
			Point p = {0, -1, a} ;
			prow[j] = p ;
		}
	}
}

void deleteMountain(Point ** &mountain, const int N){
	for(int i = 0 ; i < N ; i++){
		delete[] mountain[i];
	}
	delete[] mountain; 
}

int is_not_explored(Point * point){
	return point->front_max == 0 && point->next_max == -1 ;
}

void start(Point ** &mountain, const int N){

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			explore(mountain, N, j, i);
			if(visited_num == N * N) break ;
		}
	}

	std::cout << max_diff << std::endl ;
}

void explore(Point ** &mountain, const int N, int x, int y){

	Point * now = &mountain[y][x] ;

	if(is_not_explored(now)){		
		now->next_max = 0 ;
		int diff = make_path(mountain, N, x, y, 0) ;
		if(diff > max_diff) max_diff = diff ;
	}	

}

int make_path(Point ** &mountain, const int N, int x, int y, int from){

	Point * now = &mountain[y][x] ;
	
	if(from != 1 && x+1 < N){
		Point * right = &mountain[y][x+1];

		int diff_from_now = now->altitude - right->altitude ;
		int diff_from_head = diff_from_now + now->front_max ;
	
		if(diff_from_now > 0){
			int next_max_path = 0 ;

			if(right->next_max != -1){
				next_max_path = right->next_max + diff_from_now ;

			} else {
				right->front_max = diff_from_head;
				next_max_path = make_path(mountain, N, x+1, y, 2) + diff_from_now ;
			}

			if(next_max_path > now->next_max) now->next_max = next_max_path ;
		}
	} 
	
	if(from != 2 && x-1 >= 0){
		Point * left = &mountain[y][x-1];

		int diff_from_now = now->altitude - left->altitude ;
		int diff_from_head = diff_from_now + now->front_max ;

		if(diff_from_now > 0){
			int next_max_path = 0 ; 

			if(left->next_max != -1){
				next_max_path = left->next_max + diff_from_now ;
			} else {
				left->front_max = diff_from_head ;
				next_max_path = make_path(mountain, N, x-1, y, 1) + diff_from_now;
			}

			if(next_max_path > now->next_max) now->next_max = next_max_path ;
		}
	}
	
	if(from != 3 && y-1 >= 0){
		Point * top = &mountain[y-1][x];

		int diff_from_now = now->altitude - top->altitude ;
		int diff_from_head = diff_from_now + now->front_max ;

		if(diff_from_now > 0 ){
			int next_max_path = 0 ;
			
			if(top->next_max != -1){
				next_max_path = top->next_max + diff_from_now ;
			
			} else {
				top->front_max = diff_from_head ;
				next_max_path = make_path(mountain, N, x, y-1, 4) + diff_from_now ;
			}

			if(next_max_path > now->next_max) now->next_max = next_max_path ;
		}
	}
	
	if(from != 4 && y+1 < N){
		Point * bottom = &mountain[y+1][x];

		int diff_from_now = now->altitude - bottom->altitude ;
		int diff_from_head = diff_from_now + now->front_max ;

		if(diff_from_now > 0){
			int next_max_path = 0 ;
		
			if(bottom->next_max != -1){
				next_max_path = bottom->next_max + diff_from_now ;
			} else {
				bottom->front_max = diff_from_head ;
				next_max_path = make_path(mountain, N, x, y+1, 3) + diff_from_now;
			}

			if(next_max_path > now->next_max) now->next_max = next_max_path ;
		}
	}

	if(now->next_max == -1) now->next_max = 0 ;

	return now->next_max ;

} 





















