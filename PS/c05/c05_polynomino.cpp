#include <iostream>

int puzzle[8][8] = {0} ;
int puzzle_size ;

int piece_num ;
int pieces[6][4][4] ;
int piece_height[6] ;
int piece_width[6] ;

int _init(){
	std::cin >> piece_num ;

	for(int i = 1 ; i <= piece_num ; i++){

		std::cin >> piece_height[i] >> piece_width[i] ;
		for(int k = 0 ; k < piece_height[i] ; k++)
			for(int l = 0 ; l < piece_width[i] ; l++){
				int a ; 
				std::cin >> a ;
				if(a == 1){
					puzzle_size++ ;
					a = i ;
				}
				pieces[i][k][l] = a ;
			}
	}

	bool valid_puzzle = false;
	for(int i = 1 ; i <= 8 ; i++){
		if(puzzle_size == i * i){
			puzzle_size = i;
			valid_puzzle = true ;
		}
	}

	if(!valid_puzzle){
		std::cout << "No solution possible" << std::endl;
		return 0;
	}

	return 1; 
}

void print_piece(int piece[4][4], int h, int w);
void print_puzzle(int h, int w);

int find_next(int cur_x, int cur_y, int * next_x, int * next_y){
	//printf("[%d, %d] -> ", cur_x, cur_y);
	for(int i = cur_y ; i < puzzle_size ; i++){
		for(int j = 0 ; j < puzzle_size ; j++){
			if(puzzle[i][j] == 0){
				*next_y = i ;
				*next_x = j ;
				return 1 ;
			}
		}
	}
	return 0 ;
}

int get_x_first(int w, int piece_id){
	for(int j = 0 ; j < w ; j++){
		if(pieces[piece_id][0][j]){
			return j;
		}
	}	
	return -1; 
}

int add_piece_to_puzzle_if_possible(int x, int y, int piece_id){
	int w = piece_width[piece_id];
	int h = piece_height[piece_id];
	int piece[4][4] ; 
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++)
			piece[i][j] = pieces[piece_id][i][j] ;
	}

	int first_x = get_x_first(w, piece_id) ;
	x = x - first_x ;

	for(int i = y ; i < y + h ; i++){
		for(int j = x ; j < x + w ; j++){
			if(i < 0 || j < 0 || i >= puzzle_size || j >= puzzle_size){
				return 0 ;
			}
			if(puzzle[i][j] != 0 && piece[i-y][j-x] != 0){
				return 0 ;
			}
		}
	}

	for(int i = y ; i < y + h ; i++){
		for(int j = x ; j < x + w ; j++){
			if(piece[i-y][j-x] != 0 )
				puzzle[i][j] = piece[i-y][j-x];
		}
	}



	return 1 ; 
}

void delete_piece_from_puzzle(int x, int y, int piece_id){
	int w = piece_width[piece_id];
	int h = piece_height[piece_id];

	int first_x = get_x_first(w, piece_id);

	for(int i = y ; i < y + h; i++){
		for(int j = x - first_x ; j < x + w ; j++){
			if(i >= puzzle_size || j >= puzzle_size)
				continue ;
			if(puzzle[i][j] == piece_id){
				puzzle[i][j] = 0 ;
			}
		}
	}
	
}


int fit(int x, int y, int remain[], int remain_num){

	int cur[5] ; int cur_num ;
	
	for(int i = 0 ; i < remain_num ; i++){
		cur[i] = remain[i] ;
	}
	cur_num = remain_num ;

	for(int i = 0 ; i < cur_num ; i++){
		int isFit = add_piece_to_puzzle_if_possible(x, y, cur[i]);

		if(isFit && remain_num == 1)
			return 1;

		if(isFit && remain_num != 1){
			int next_x; int next_y; 

			if(!find_next(x, y, &next_x, &next_y)){
				std::cout << "unintended" <<std::endl;
			}

			int next[5] ; int next_num ; int k = 0;
			next_num = cur_num - 1 ;
			for(int j = 0 ; j < cur_num ; j++){
				if(i != j)
					next[k++] = cur[j];
			}

			if(fit(next_x, next_y, next, next_num))
				return 1 ;
			else{
				delete_piece_from_puzzle(x, y, cur[i]);
			}
		}
	}

	return 0 ;
}

int main(){

	if(!_init())
		return 0 ;

	int remain[5] ;
	for(int i = 1 ; i <= piece_num ;i++)
		remain[i-1] = i;

	if(!fit(0, 0, remain, piece_num)){
		std::cout << "No solution possible" << std::endl;
		return 0;
	}
	print_puzzle(puzzle_size, puzzle_size);
	return 0 ;
}

void print_puzzle(int h, int w){
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++){
			std::cout << puzzle[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void print_piece(int piece[4][4], int h, int w){
	for(int k = 0 ; k < h ; k++){
		for(int l = 0 ; l < w ; l++){
			std::cout << piece[k][l] << " ";
		}
			std::cout << std::endl ;
	}
	std::cout << std::endl;
}