#include <iostream>
#include <queue>

std::queue<int> q ;

int main(){

	std::ios_base::sync_with_stdio(0x0);
	std::cout.tie(0x0);

	int N ; std::cin >> N;
	int K ; std::cin >> K;

	for(int i = 1 ; i <= N ; i++){
		q.push(i);
	}	

	std::cout << "<" ;
	while(!q.empty()){	
		for(int i = 0 ; i < K ; i++){
			int a = q.front(); 
			if(i != K-1){
				q.pop();
				q.push(a);
			} else {
				q.pop();
				std::cout << a ;
			}
		}
		if(q.empty()){
			std::cout << ">\n" ; 
		} else {
			std::cout << ", " ;
		}
	}


	return 0 ; 
}