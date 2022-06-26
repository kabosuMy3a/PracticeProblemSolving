#include <iostream>

int nums[100000] ;

int main(){
	
	int N, S ; std::cin >> N >>  S  ;
	for(int i = 0 ; i < N ; i++){
		std::cin >> nums[i] ;
	}

	int front = 0 ; int rear = 0 ; int min_nums = 100001; int sum = nums[0] ; int cur_nums = 1 ;
	while(front != N){
		if(sum >= S && min_nums > cur_nums) min_nums = cur_nums ;
		if(sum >= S){
			sum -= nums[front];			
			front++ ;
			cur_nums -= 1 ;
		} else {
			rear++ ;
			if(rear < N){
				sum += nums[rear] ;
				cur_nums += 1 ;
			} else {
				if(sum < S) break; 
			}
		}
	}

	if(min_nums == 100001) std::cout << 0 << "\n" ;
	else std::cout << min_nums << "\n" ;

	return 0;
}