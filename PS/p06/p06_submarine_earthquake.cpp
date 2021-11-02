#include <iostream>

int cables[500] ;

int main(){

	int N ; std::cin >> N;
	for(int i = 0 ; i < N ; i++) std::cin >> cables[i] ;
	 


	int b[6][4] = {
		{3,3,2,1}, 
		{2,2,2,2}, 
		{2,3,3,1}, 
		{1,3,3,2}, 
		{2,2,2,2}, 
		{1,2,3,3}};

	int a[24][5] = {
	{4,4,3,2,1},
	{3,3,2,2,2},
	{3,3,3,3,1},
	{2,2,3,3,2},
	{3,3,2,2,2},
	{2,2,2,3,3},
	{3,4,4,2,1},
	{2,3,3,2,2},
	{2,4,4,3,1},
	{1,4,4,3,2},
	{2,3,3,2,2},
	{1,3,3,3,3},
	{3,3,3,3,1},
	{2,2,3,3,2},
	{2,3,4,4,1},
	{1,3,4,4,2},
	{2,2,3,3,2},
	{1,2,4,4,3},
	{3,3,2,3,3},
	{2,2,2,3,3},
	{2,3,3,2,2},
	{1,3,3,3,3},
	{2,2,2,3,3},
	{1,2,3,4,4}};

	int min = 423123312 ;
	int min_idx ;

	if(N == 4){
		for(int i = 0 ; i < 6 ; i++){
			int sol = 0 ;
			for(int j = 0 ; j < 4 ; j++){
				sol += b[i][j] * cables[j] ;
			}
			if(min > sol){
				min = sol;
				min_idx = i ;
			}
			std::cout << sol << " ";
		}
		std::cout << "\n";
		for(int i = 0 ; i < 4 ;i++)
			std::cout << b[min_idx][i] << " ";
		std::cout << "\n";
	}


	if(N == 5){
		for(int i = 0 ; i < 24 ; i++){
			int sol = 0 ;
			for(int j = 0 ; j < 5 ; j++){
				sol += a[i][j] * cables[j] ;
			}
			if(min > sol){
				min = sol;
				min_idx = i ;
			}
			std::cout << sol << " ";
		}
		std::cout << "\n";
		for(int i = 0 ; i < 5 ; i++ )
			std::cout << a[min_idx][i] <<" ";
		std::cout << "\n";
	}




	return 0 ;
}