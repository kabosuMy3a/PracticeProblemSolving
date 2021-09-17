#include <iostream>
#include <queue>

typedef struct {

	int x ;

	int y ;

	int altitude ;

	int visited ; 

} Point ;

std::ostream& operator<<(std::ostream &o, const Point p){
    return o << p.altitude ;  
}


bool operator<(const Point a, const Point b){
	return a.altitude < b.altitude ;
}

void modelingMountain(Point ** &mountain, std::priority_queue<Point> &highestHeap, const int N );
void deleteMountain(Point ** &mountain, const int N);
void draw_path(Point ** &mountain, const int N, Point now, int diff_from_head);

int visited_point_num = 0 ;
int max_diff = 0 ;

int main(){

	int n;
	std::cin >> n ; 
	const int N  = n ;

	Point ** mountain = new Point * [N] ;	
	std::priority_queue<Point> highestHeap ; 
	modelingMountain(mountain, highestHeap, N) ;

	while(true){
		if(visited_point_num == N * N || highestHeap.empty()) break; 

		Point top = highestHeap.top() ;
		highestHeap.pop();
		if(mountain[top.y][top.x].visited ==1) continue ;

		draw_path(mountain, N, top, 0);

	}

	std::cout << max_diff << std::endl; 

	deleteMountain(mountain, N) ; 


	return 0 ; 
}

void modelingMountain(Point ** &mountain, std::priority_queue<Point> &highestHeap, const int N ){
	for(int i =  0 ; i < N ; i++){
		Point * prow = new Point [N] ;
		mountain[i] = prow ; 
		for(int j = 0 ; j < N ; j++){
			int a ; 
			std::cin >> a ;
			Point p = {j, i, a, 0} ;
			prow[j] = p ;
			highestHeap.push(p);
		}
	}
}

void deleteMountain(Point ** &mountain, const int N){
	for(int i = 0 ; i < N ; i++){
		delete[] mountain[i];
	}
	delete[] mountain; 
}

void draw_path(Point ** &mountain, const int N, Point now, int diff_from_head){

	int x = now.x ;
	int y = now.y ;

	visited_point_num += 1 ;
	mountain[now.y][now.x].visited = 1 ;

	if(x+1 < N){
		if(mountain[y][x+1].visited !=1){
			Point right = mountain[y][x+1] ;
			int diff = now.altitude - right.altitude ;
			if(diff > 0)
				draw_path(mountain, N, right, diff_from_head + diff);
		}
	}

	if(x-1 >= 0){
		if(mountain[y][x-1].visited != 1){
			Point left = mountain[y][x-1] ;
			int diff = now.altitude - left.altitude ;
			if(diff > 0)
				draw_path(mountain, N, left, diff_from_head + diff);
 		}

	}

	if(y+1 < N){
		if(mountain[y+1][x].visited != 1){
			Point bottom = mountain[y+1][x] ;
			int diff = now.altitude - bottom.altitude ;
			if(diff > 0)
				draw_path(mountain, N, bottom, diff_from_head + diff);
		}
	}

	if(y-1 >= 0){
		if(mountain[y-1][x].visited != 1){
			Point top = mountain[y-1][x] ;
			int diff = now.altitude- top.altitude ;
			if(diff > 0)
				draw_path(mountain, N, top, diff_from_head + diff);
		}
	}

	if(diff_from_head > max_diff) max_diff = diff_from_head ;

}
