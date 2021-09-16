#include <iostream>

typedef struct {

	int x ;

	int y ;

	int altitude ;

	int visited ; 

} Point ;

std::ostream& operator<<(std::ostream &o, const Point p)
{
    return o << p.altitude ;  
}


int main(){

	int n;
	std::cin >> n ; 
	const int N  = n ;


	Point ** mountain = new Point * [N] ;

	for(int i =  0 ; i < N ; i++){
		Point * prow = new Point [N] ;
		mountain[i] = prow ; 
		for(int j = 0 ; j < N ; j++){
			int a ; 
			std::cin >> a ;
			Point p = {j, i, a, 0} ;
			prow[j] = p ;
		}
	}

	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			std::cout << mountain[i][j] << " " ;
		}
		std::cout << std::endl ; 
	}


	for(int i = 0 ; i < N ; i++){
		delete[] mountain[i];
	}
	delete[] mountain; 


	return 0 ; 
}