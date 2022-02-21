#include <iostream>
int N ;
int a[4][200001];
int is_win[200001];

int main(){
	
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int no ; std::cin >> no;
		int a1,a2,a3,a4 ;
		std::cin >> a1 >> a2 >> a3 >> a4 ;
		a[0][no] = a1 ;
		a[1][no] = a2 ;
		a[2][no] = a3 ;
		a[3][no] = a4 ;
		is_win[no] = 0 ;
	}

	for(int i = 0 ; i < 4 ; i++){
		int cur_subject_max = -1 ;
		int cur_subject_max_idx = 0 ;
		for(int j = 1 ; j <= N ; j++){
			if(!is_win[j] && cur_subject_max < a[i][j]){
				cur_subject_max = a[i][j];
				cur_subject_max_idx = j ;
			}
		}
		is_win[cur_subject_max_idx] = 1 ; 
		std::cout << cur_subject_max_idx << " ";
	}

	return 0;
}