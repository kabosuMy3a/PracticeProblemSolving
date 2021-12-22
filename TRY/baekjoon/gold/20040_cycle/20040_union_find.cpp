#include <iostream>
#include <cstring>

int head[500000];
int height[500000];

int find_head(int x){
	if(head[x] == x) return x ;
	return head[x] = find_head(head[x]) ;
}

int union_head(int x, int y){
	int x_head = find_head(x) ;
	int y_head = find_head(y) ;

	if(x_head == y_head) {
		return 1 ;
	}
	
	if(height[x_head] < height[y_head]){
		head[x_head] = y_head;
	} else{
		head[y_head] = x_head ;
		if(height[x_head] == height[y_head]){
			height[x_head] += 1; 
		}
	}

	return 0 ;
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);

	int N, M ; std::cin >> N >> M ;
	for(int i = 0 ; i < N ; i++){
		head[i] = i ;
		height[i] = 0 ;
	}
	
	for(int i = 0 ; i < M ; i++){
		int a, b ; std::cin >> a >> b;
		if(union_head(a, b)){
			std::cout << i+1 << std::endl;
			exit(0);
		}
	}

	std::cout << 0 << std::endl;
	return 0 ;
}