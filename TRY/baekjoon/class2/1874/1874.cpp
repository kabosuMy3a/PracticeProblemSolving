/*
8
4
3
6
8
7
5
2
1
*/

#include <iostream>
#include <deque>

int st[100000];
int N ;

int op_list[100000];
int op_list_idx = 0 ;

int main(){
	std::cin >> N ;
	int inserted = 0 ; int cur = 0 ;
	for(int i = 0 ; i < N  ; i++){
		int a ; std::cin >> a;
		if(a > inserted){
			int j ;
			for(j = inserted + 1 ; j <= a ; j++){
				st[cur++] = j ;
				op_list[op_list_idx++] = 1 ;
			}
			inserted = j - 1  ;
			st[--cur] =0 ;
			op_list[op_list_idx++] = 2 ;

			std::cout << a << "\n";
		} else {
			int b = st[cur - 1] ;
			std::cout << a << " " <<b << "\n";
			if(b < a){
				std::cout << "NO" << "\n";
				return 0;
			}
			else if(b == a){
			 	st[--cur] = 0 ;
			 	op_list[op_list_idx++] = 2 ;
			}
			else{
				while(true){
					int c = st[cur - 1] ;
					st[--cur] = 0 ;
					op_list[op_list_idx++] = 2 ;
					if(c == a) break ; 
				}
			}

		}
	}

	for(int i = 0 ; i < op_list_idx ; i++){
		if(op_list[i] == 1) std::cout << "+" <<"\n";
		else std::cout << "-" << "\n";
	}


	return 0;
}
