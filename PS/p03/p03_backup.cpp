#include <iostream>
#include <random>
#include <fstream>

class heaviest_queue {

private:  

	long long index ; 
	long long capacity ;
	int * max_heap ;

	void bottom_up_balancing(){
		long long ni = index ;
		while(ni > 1){
			long long oi = ni ;
			ni = ni / 2;
			if(max_heap[ni] < max_heap[oi]){
				int temp = max_heap[ni] ;
				max_heap[ni] = max_heap[oi];
				max_heap[oi] = temp ;
			} else 
				break ;
		}

	}

	void top_down_balancing(){
		long long ni = 1 ;
		while(1){
			long long oi = ni ;
			ni = ni * 2 ;
			if(ni > index) break ;
			else if(ni == index){
			} else {
				if(max_heap[ni] < max_heap[ni+1]) ni += 1;
			}

			if(max_heap[oi] < max_heap[ni]){
				int temp = max_heap[ni];
				max_heap[ni] = max_heap[oi] ;
				max_heap[oi] = temp ;
			} else 
				break ;
		}

	}

	void increase_queue_size(int new_capacity){
		int * resized_heap = new int [new_capacity + 1] ;
		for(long long i = 1 ; i <= capacity ; i++){
			resized_heap[i] = max_heap[i] ;
		}

		capacity = new_capacity ;
		delete[] max_heap ; 
		max_heap = resized_heap ;

	}

public:


	heaviest_queue(){
		index = 0 ;
		capacity = 1000 * 1000 ;
		max_heap = new int[1000 * 1000 + 1] ;
 		
	}

	void push(int w){
		if(index == capacity - 1 ){
			increase_queue_size(capacity * 2) ;
		}

		max_heap[++index] = w ;
		bottom_up_balancing() ;
	}

	void pop(){
		if(empty()) return ;

		int temp = max_heap[1] ;
		max_heap[1] = max_heap[index] ;
		max_heap[index] = temp ;

		index -= 1 ;
		top_down_balancing(); 

	}

	int top(){
		return max_heap[1] ;
 	}

 	bool empty(){
 		return index == 0 ; 
 	}


	~heaviest_queue(){
		delete[] max_heap ;
	}


	int * make_sorted_list(long long * size){

		int * sorted_list = new int [index] ;
		long long i = 0 ;
		while(!empty()){
			sorted_list[i++] = top() ;
			pop();
		}
		*size = i ;
		return sorted_list ;
	}

};

int main(){

	int m ; 
	std::cin >> m ;

	if(m == 0 ){
		std::cout << 0 << std::endl ;
	}

	heaviest_queue heaviestQueue = heaviest_queue() ;
	
	int w; 
	long long num_carrier = 0 ; 

	
	while(std::cin >> w){
		if(w > m || w <= 0) 
			continue ;
		if(w == m) {
			num_carrier += 1 ;
			continue ;
		}
		heaviestQueue.push(w);
	}
	
	/*
	
	std::random_device rd ;
	std::mt19937 gen(rd()) ;
	std::uniform_int_distribution<int> dis(1, 100000);



	std::ofstream fof("./p03_inputs/rp03_input5.txt");
	fof << m << std::endl; 

	for(int i = 0 ; i < 10000 ; i++){
		int n = dis(gen);
		heaviestQueue.push(n);
		fof << n << std::endl; 
	}
	
	*/

	long long sorted_list_size = 0 ;
	int * sorted_list = heaviestQueue.make_sorted_list(&sorted_list_size);

	long long front = 0 ;
	long long rear = sorted_list_size - 1;
	
	while(1){
		if(front == rear){
			num_carrier += 1;
			break ; 
		} else if(front > rear){
			break ; 
		} else {
			int f = sorted_list[front] ;
			int r = sorted_list[rear] ;
			if(f + r <= m){	
				rear -= 1 ;
			} else {
			}
			front += 1 ;
			num_carrier += 1 ;
		}

	}

	std::cout << num_carrier << std::endl ;

	delete [] sorted_list ;	

	return 0 ;
}