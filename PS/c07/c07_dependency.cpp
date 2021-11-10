#include <iostream>
#include <cstring>

int head[10001] ;
int disjoint[10001] ;

void change_all_head(int N, int from, int to){
	for(int i = 1 ; i <= N ; i++){
		if(head[i] == from)
			head[i] = to ;
	}
}

int check(int N, int first, int second){
	int first_head = head[first] ;
	int second_head = head[second];

	if((first_head == 0) && (second_head == 0)){

		head[first] = first ;
		head[second] = second ;
		disjoint[first] = second ;
		disjoint[second] = first ;

	} else if(first_head == 0) {

		head[first] = disjoint[second_head] ;

	} else if(second_head == 0){

		head[second] = disjoint[first_head] ;
		
	} else if(first_head != second_head) {

		int first_disjoint = disjoint[first_head];
		int second_disjoint = disjoint[second_head];

		if(first_disjoint == second_head)
			return 0 ;

		change_all_head(N, second_disjoint, first_head);
		change_all_head(N, second_head, first_disjoint);

		disjoint[second_head] = 0 ;
		disjoint[second_disjoint] = 0 ;

	} else if(first_head == second_head) {
		return 1 ;
	}

	return 0 ;
}


int main(){
	memset(head, 0, sizeof(head));
	memset(disjoint, 0, sizeof(disjoint));
	int N ; scanf("%d %*d", &N) ; 
	int cnt = 1 ;
	while(42){
		int f ; int s ; scanf("%d %d", &f, &s);
		if(check(N, f, s)){ 
			std::cout << cnt << std::endl;
			break;
		}
		cnt++; 
	}
	return 0 ;
}