#include <iostream>
#include <algorithm>
#include <queue>
int N ;
std::pair<int, int> schedules[200000];
std::priority_queue<int> rooms ;

int main(){
	std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int a, b; std::cin >> a >> b;
		schedules[i] = {a,b};
	}
	std::sort(schedules, schedules + N);
	rooms.push(schedules[0].second * -1);
	for(int i = 1 ; i < N ; i++){
		if(rooms.top() * -1 <= schedules[i].first) rooms.pop();
		rooms.push(schedules[i].second * -1);
	}

	std::cout << rooms.size() << "\n" ;

	return 0;
}