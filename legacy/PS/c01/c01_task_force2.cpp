#include <iostream>

///////////////////////////
//TODO: DELETE STL QUEUE///
///////////////////////////
#include <queue>

unsigned int num_qualified = 0 ;

typedef struct{

	int id ;
	int state ;
	int fnum ;

} MarineCorps ;


int main(){

	int n ; int k ; int INPUT_NUM ;
	std::cin >> n >> k >> INPUT_NUM ;
	const int N = n; const int K = k; 
	
	num_qualified += N ;

	int ** friendship_matrix ;
	
	friendship_matrix = new int * [N] ;
	for(int i = 0 ; i < N ; i++){
		friendship_matrix[i] = new int[N] ;
		for(int j = 0 ; j < N ; j++){
			friendship_matrix[i][j] = 0 ;
		}
	}

	MarineCorps * roster = new MarineCorps[N] ;

	for(int i = 0 ; i < N  ; i++){
		MarineCorps m = {i, 1, 0} ;
		roster[i] = m; 
	}

	for(int i = 0 ; i < INPUT_NUM ; i++){
		int a ; int b;
		std::cin >> a  >> b ;
		a -= 1; b -= 1; 

		friendship_matrix[a][b] = 1 ;
		friendship_matrix[b][a] = 1 ;

		roster[a].fnum += 1 ;
		roster[b].fnum += 1 ; 

	}

	////////////////////////
	//TODO: NO USE STL QUEUE
	////////////////////////	
	std::queue<MarineCorps * > erase_queue ;

	for(int i = 0 ; i < N ; i++){
		MarineCorps * m = &roster[i] ;
		if(m->fnum < K){
			m->state = 0 ;
			erase_queue.push(m); 
		}
	}

	while(1){
		if(erase_queue.size() == 0 ) break;
		if(erase_queue.size() == num_qualified){
			num_qualified = 0 ; 
			break ;
		}
		

		num_qualified -= 1;
		MarineCorps * m = erase_queue.front();
		erase_queue.pop();

		m->state = -1 ;
		m->fnum = 0 ;
		int m_id = m->id ; 

		for(int roster_index = 0 ; roster_index < N ; roster_index++){
			if(friendship_matrix[m_id][roster_index] == 1){
				friendship_matrix[m_id][roster_index] = 0 ;
				friendship_matrix[roster_index][m_id] = 0 ;

				MarineCorps * mm = &roster[roster_index] ;
				mm->fnum -= 1 ;
				if(mm->fnum < k && mm->state == 1){
					mm->state = 0 ;
					erase_queue.push(mm);
				}
			}
		} 
	}

	std::cout <<  num_qualified << std::endl; 

	for(int i = 0 ; i < N ; i++){
		delete [] friendship_matrix[i] ;
	}

	delete [] friendship_matrix ;
	delete [] roster ;

	return 0; 
}