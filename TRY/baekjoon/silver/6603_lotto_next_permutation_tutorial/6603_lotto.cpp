#include <iostream>
#include <algorithm>

int s[12] ;
int choice[12] ;
int N ;

void print_perm(){
	for(int i = 0 ; i < N ; i++)
		if(choice[i]==1) std::cout << s[i] << " ";
	std::cout << "\n" ;
}

int main(){
	int is_first = 1 ;
	while(true){
		std::cin >> N ;
		if(N == 0) break ;
		else {
			if(!is_first) std::cout << "\n" ;
			else is_first = 0;
		}  

		for(int i = 0 ; i < N ; i++){
			std::cin >> s[i] ;
			if(i < 6) choice[i] = 1;
			else choice[i] = 0 ;
		}

		print_perm();
		while(std::prev_permutation(choice, choice+N)) print_perm();

	}

	return 0 ;
}