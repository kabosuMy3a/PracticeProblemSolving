#include <iostream>

long long original_ans[51] ;

int rods[3][50];
int rod_size[3] ;

int N ; int K ;

int rod_order[3] ;
int straight = 1 ;
long long solution = 0;

long long f(int n);
int _init_setting();
void _set_straight();
void draw_hanoi();

void mv_ring(int from, int to, int from_idx){

	int ring = rods[from][from_idx] ;

	int is_straight = 0 ;
	if(ring == straight)
		is_straight=  1 ;

	if(is_straight){
		int to_idx = rod_size[to] ;
		for(int i = 0 ; i < straight ; i++){
			rods[to][to_idx + i] = rods[from][from_idx + i] ;
			rods[from][from_idx + i] = 0 ;
		}
		
		std::cout << "straight-"<< straight << std::endl ;
		rod_size[from] -= straight ;
		rod_size[to] += straight ;
		solution += f(straight);

		to_idx -= 1; 
		while(to_idx >= 0 && (rods[to][to_idx] == straight + 1)){
			to_idx -= 1;
			straight += 1 ;
		}

	} else {
		while(1){

			int escape_to = 3 - from - to ;
			int ring_need_to_move = 0 ;

			int new_from_idx = from_idx + 1;
			int new_from = from ;

			if(new_from_idx < rod_size[from]){
				ring_need_to_move = rods[from][new_from_idx];
			}

			for(int to_idx = 0 ; to_idx < rod_size[to] ; to_idx++){
				int to_ring = rods[to][to_idx] ;
				if(ring > to_ring && to_ring > ring_need_to_move){
					ring_need_to_move = to_ring ;
					new_from = to ;
					new_from_idx = to_idx ;
					break ;
				}
			}	

			if(ring_need_to_move != 0){				
				std::cout << ring_need_to_move << " from:" << new_from << " -> " << "to: " << escape_to <<std::endl ;
				mv_ring(new_from, escape_to, new_from_idx);				
			} else {
				break ;
			}
		}

		rods[to][rod_size[to]] = rods[from][from_idx] ;
		rods[from][from_idx] = 0 ;
		rod_size[from] -= 1 ;
		rod_size[to] += 1;
		solution += 1 ; 

	}

}

int main(){

	if(_init_setting() == 0){
		std::cout << 0 << std::endl ;
		return 0 ;
	}

	_set_straight();
	/*if(straight == N){
		std::cout << f(N) << std::endl;
		return 0 ;
	}*/

	draw_hanoi();

	std::cout << N  << " from: " << rod_order[0] << " -> to: " << rod_order[2] << std::endl ;
	mv_ring(rod_order[0], rod_order[2], 0);
	solution += f(rods[rod_order[1]][0]); 

	std::cout << solution << std::endl ;


	return 0 ;
}


long long f(int n){
	return original_ans[n];
}

int _init_setting(){
	original_ans[0] = 0 ;
	original_ans[1] = 1 ;
	for(int i = 2 ; i <= 50 ; i++){
		original_ans[i] = original_ans[i-1] * 2 + 1 ;
	}

	std::cin >> N >> K ;

	rod_order[2] = K-1 ;

	for(int i = 0 ; i < 3 ; i++){
		std::cin >> rod_size[i] ;
		int ring_no_need_to_move = 0 ;

		for(int j = 0 ; j < 50 ; j++){
			if(j >= rod_size[i]){
				rods[i][j] = 0 ;
				continue ;
			}
			int ring ;
			std::cin >> ring ;
			if(ring == N && i == rod_order[2] ){
				N -= 1;
				ring_no_need_to_move += 1;
				continue ;
			}
			rods[i][j - ring_no_need_to_move] = ring ;
		}

	}

	if(N == 0)
		return 0 ;

	for(int i = 0 ; i < 3 ; i++){
		if(i == rod_order[2]) 
			continue ;
		if(rods[i][0] == N)
			rod_order[0] = i;
		else 
			rod_order[1] = i ;
	}

	return 1 ;
}

void _set_straight(){
	for(int i = 0 ; i < 3 ; i++){

		int rear = rod_size[i] - 1 ;

		if(rear <= 0 || rods[i][rear] != 1)
			continue;

		while(rear != 0){
			int a = rods[i][rear] ;
			int b = rods[i][--rear];

			if(b - a == 1)
				straight += 1 ;
		}		
	}
}

void draw_hanoi(){
	for(int i = 49 ; i >= 0  ; i--){
		int check = 0 ;

		int a = rods[rod_order[0]][i];
		int b = rods[rod_order[1]][i];
		int c = rods[rod_order[2]][i];

		check = a+b+c ;

		if(check){
			std::cout << a << "  " << b << "  " << c << std::endl;
		}
	} 
	std::cout << std::endl << rod_size[rod_order[0]] << "  " << rod_size[rod_order[1]] << "  " << rod_size[rod_order[2]] << std::endl ;
	std::cout << "straight: " << straight << "\n" << std::endl;
}

