#include <iostream>
#include <cstring>

int head[500000];
int dependency[500000];

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);

	int N, M ; std::cin >> N >> M ;
	memset(head, -1, N * sizeof(int));

	for(int i = 0 ; i < M ; i++){
		int a, b ; std::cin >> a >> b;
		if(head[a] == -1 && head[b] == -1){
			head[a] = a ;
			head[b] = a ;
		}

		else if(head[a] == -1 && head[b] != -1){
			head[a] = head[b];
		}

		else if(head[a] != -1 && head[b] == -1){
			head[b] = head[a];
		}
		else if(head[a] != -1 && head[b] != -1) {
			if(head[a] == head[b]){
				std::cout << i+1 << std::endl;
				break ; 
			} 
			int tmp = head[b];
			for(int i= 0 ; i < N ; i++){
				if(head[i] == tmp){
					head[i] = head[a];
				}
			}
		}
	}

	std::cout << 0 << std::endl;
	return 0 ;
}