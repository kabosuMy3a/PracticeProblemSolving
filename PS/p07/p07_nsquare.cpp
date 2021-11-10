#include <iostream>
#include <cstring>

int tasks[100001] ;
int available_area[100001];
int reserved_area[100001];

int main(){

	memset(tasks, 0 ,sizeof(tasks));
	int LAST_DAY ; std::cin >> LAST_DAY ;
	int DUE ; std::cin >> DUE ;
	int TASK_NUM; std::cin >> TASK_NUM ;
	for(int i = 0 ; i < TASK_NUM ; i++){
		int ti ; std::cin >> ti;
		tasks[ti] += 1 ;
	}

	for(int k = 1 ; k <= LAST_DAY ; k++){

		reserved_area[0] = 0;
		int default_area = k * (DUE+1) ;
		available_area[1] = default_area ;

		int i ;
		for(i = 2 ; i <= LAST_DAY - DUE ; i++){
			int reserved_tasks = reserved_area[i-2] + tasks[i-1] ; 
			if(reserved_tasks > k ){
				reserved_area[i-1] = reserved_tasks - k ;
			} else {
				reserved_area[i-1] = 0 ; 
			}
			available_area[i] = default_area - reserved_area[i-1];

			if(available_area[i] < tasks[i]){
				break ;
			}
		}

		if(i == LAST_DAY - DUE + 1){
			std::cout << k << std::endl;
			break;
		}
	}

	return 0 ;
}