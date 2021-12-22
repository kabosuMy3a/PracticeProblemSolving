#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>

/////////////////////////////////////////////////
//idea: previous year slide shown in 2021 class//
/////////////////////////////////////////////////

std::pair<int, int> job_seekers[8000];
std::stack<int> groups ;

int main(){
	int N ; std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int x, y;
		std::cin >> x >> y;
		job_seekers[i] = std::make_pair(x,y);
	}
	std::sort(job_seekers, job_seekers + N);

	groups.push(job_seekers[0].second);
	for(int i = 1 ; i < N ; i++){
		int cur_pt_score = job_seekers[i].second;
		int max_pt_score_of_group = cur_pt_score ;
		while(true){
			if(groups.empty()){
				groups.push(max_pt_score_of_group);
				break;
			}	

			if(cur_pt_score < groups.top()){
				if(max_pt_score_of_group < groups.top())
					max_pt_score_of_group = groups.top() ;
				groups.pop();

			} else {
				groups.push(max_pt_score_of_group);
				break;
			}
		}
	}

	std::cout << groups.size() << std::endl;

	return 0 ;
}