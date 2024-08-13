#include <iostream>

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

void swap_point(Point & a, Point & b){
	Point temp = a ;

	a.x = b.x ;
	a.y = b.y ;
	a.altitude = b.altitude ;
	a.visited = b.visited ;

	b.x = temp.x ;
	b.y = temp.y ;
	b.altitude = temp.altitude ;
	b.visited = temp.visited ;
}

class highest_queue {

private:

	int index ;
	Point * max_heap ; 
	int max ; 


public:

	highest_queue(const int N){
	
		max_heap = new Point[N * N + 1] ;
		index = 0 ; 
		max = N * N + 1;

	}

	void bottom_up_balancing(){
		int ni = index ;
		while(ni > 1){
			int oi = ni ;
			ni = ni / 2 ;
			if(max_heap[ni] < max_heap[oi]){
				swap_point(max_heap[ni], max_heap[oi]);

			} else 
				break; 
		}
	}

	void push(Point p){
		if(index != max -1)
			max_heap[++index] = p ;
		bottom_up_balancing();
	}

	Point top(){
		return max_heap[1] ; 
	}

	void top_down_balancing(){
		int ni = 1 ;
		while(true){
			int oi = ni ;
			ni = ni * 2; 
			if(ni > index) break ;
			else if(ni == index){
			} else {
				if(max_heap[ni] < max_heap[ni+1])
					ni += 1 ;
			}
			if(max_heap[oi] < max_heap[ni]){
				swap_point(max_heap[oi], max_heap[ni]);
			} else 
				break;
		}
	}

	void pop(){
		if(empty())
			return ;
		swap_point(max_heap[1], max_heap[index]) ;
		index -= 1 ;
		top_down_balancing();
	}

	bool empty(){
		return index == 0 ;
	}

	~highest_queue(){
		delete [] max_heap ;
	}

};

void modelingMountain(Point ** &mountain, highest_queue &highestHeap, const int N );
void deleteMountain(Point ** &mountain, const int N);
void draw_path(Point ** &mountain, const int N, Point now, int diff_from_head);

int visited_point_num = 0 ;
int max_diff = 0 ;

int main(){

	int n;
	std::cin >> n ; 
	const int N  = n ;

	Point ** mountain = new Point * [N] ;	
	highest_queue highestHeap = highest_queue(N) ; 

	
	modelingMountain(mountain, highestHeap, N); 

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

void modelingMountain(Point ** &mountain, highest_queue &highestHeap, const int N ){
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
