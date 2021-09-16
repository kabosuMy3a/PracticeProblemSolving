#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <unistd.h>

int solve(const int N){

	std::vector<int> deck ;
	
	for(int i = 1; i <= N ; i++){
		deck.push_back(i);
	}	

	int front = 0 ;
	int rear = N-1 ;

	while(front != rear){
		if((rear - front) == 1){
			front += 1 ;
			break ;
		}

		deck.push_back(deck[front+1]) ;
		front += 2 ;
		rear += 1 ;

	}

	std::cout << deck[front] << std::endl ;

	return deck[front];


}

int solve_with_queue_best_solution(const int N){

	std::queue<int> queue ;

	for(int i = 1 ; i <= N ; i++){
		queue.push(i);
	}

	while(queue.size() != 1){
		queue.pop();
		queue.push(queue.front());
		queue.pop();
	}

	std::cout << queue.front() << std::endl ;

	return queue.front();

}

void test(){

	while(true){
		std::random_device rd ;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(1, 500000) ;

		const int N = dis(gen) ;
		if(solve_with_queue_best_solution(N) == solve(N)){
			std::cout << "N: " <<  N << " = OK\n" << std::endl;
			usleep(100000);
		}

	}

}

int main(){
	/*
	int n ;
	std::cin >> n ;
	const int N = n ;
	*/

	test();

 
	return 0 ;
}