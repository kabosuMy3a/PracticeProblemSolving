#include <iostream>
#include <utility>

std::pair<int, int> job_seekers[8000];
int interview_group[8000];
int interview_group_num = 0 ;

bool is_must_same_group(std::pair<int, int> a, std::pair<int, int> b){
	int x1 = a.first ; int x2 = b.first ;
	int y1 = a.second ; int y2 = b.second ;
	if(((x1 < x2) && (y1 > y2)) || ((x1 > x2) && (y1 < y2)))
		return true ;
	return false; 
}

void set_interview_group(int idx, std::pair<int, int> new_job_seeker){
	interview_group[idx] = idx; 
	interview_group_num += 1; 

	for(int i = 0 ; i < idx ; i++){
		std::pair<int, int> cur_job_seeker = job_seekers[i];
		int head = interview_group[i] ;
		if(head == idx) continue ;

		if(is_must_same_group(new_job_seeker, cur_job_seeker)){
			interview_group_num -= 1;
			interview_group[i] = idx ;

			for(int j = 0 ; j < idx ; j++){
				if(interview_group[j]== head)
					interview_group[j] = idx;
			}

		}
	}
}

int main(){
	int N ; std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int x, y;
		std::cin >> x >> y;
		job_seekers[i] = std::make_pair(x,y);
		set_interview_group(i, job_seekers[i]);
	}

	std::cout << interview_group_num << std::endl;

	return 0 ;
}