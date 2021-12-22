#include <iostream>
#include <utility>
#include <queue>
#include <vector>

struct Compare{
	bool operator()(int a, int b){
		if(a == -b) return a > b ;
		if(a < 0) a *= -1;
		if(b < 0) b *= -1;

		return a > b ; 
	}
};

std::priority_queue<int, std::vector<int>, Compare> abs_q ; 


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int N ; std::cin>> N;

	for(int i = 0 ; i < N ; i++){
		int a ; std::cin >> a ;
		if(a == 0){
			if(abs_q.empty()){
				std::cout << 0 << "\n";
				continue ;
			}
			std::cout << abs_q.top() << "\n";
			abs_q.pop();
		} else {
			abs_q.push(a);
		}
	}

	return 0 ; 
}