#include <iostream>
#include <queue>
#include <cassert>
#include <vector>

int JOHN, COW ;
int catch_time[100001];
std::vector<int> v ;

int num_ways = 1 ;
void find_ways(int c);

int main(){
    std::ios_base::sync_with_stdio(0x0);
	std::cin >> JOHN >> COW ;

	if(COW <= JOHN){
		std::cout << JOHN - COW << "\n";
		for(int i = JOHN ; i >= COW ; i--) std::cout << i << " ";
        std::cout << "\n";
		return 0 ;
	}

	for(int i = 0 ; i <= 100000 ; i++) catch_time[i] = -1 ;
	catch_time[JOHN] = 0;
	std::queue<int> bfs_q ;
	bfs_q.push(JOHN);
	
	while(!bfs_q.empty()){
		int cur = bfs_q.front();
		bfs_q.pop();

		int next = cur - 1;
		if(next >= 0 && catch_time[next] == -1){
			bfs_q.push(next);
			catch_time[next] = catch_time[cur] + 1;
		}

		next = cur + 1;
		if(next <= COW + 1 && catch_time[next] == -1){
			bfs_q.push(next);
			catch_time[next] = catch_time[cur] + 1;

		}

		next = cur * 2;
		if(next <= COW + 1 && catch_time[next] == -1){
			bfs_q.push(next);
			catch_time[next] = catch_time[cur] + 1;
		}
	}

	std::cout << catch_time[COW] << "\n";
	find_ways(COW);
	return 0 ;
}

void find_ways(int c){
    
	int cur_ways = 0 ;
    v.push_back(c);
	if(c == JOHN){
        for(auto it = v.rbegin() ; it != v.rend() ; it++) std::cout << *it << " ";
        std::cout <<"\n";
        exit(0);
    }
	if(c +1 <= 100000 && (catch_time[c+1] == catch_time[c] - 1)){
		cur_ways += 1;
		find_ways(c+1);
	}
	if(c - 1 >= 0 && (catch_time[c-1] == catch_time[c] - 1)){
		cur_ways += 1;
		find_ways(c-1);
	}

	if(c % 2 == 0 && catch_time[c/2] == catch_time[c] - 1){
		cur_ways += 1 ;
		find_ways(c/2);
	}

	if(cur_ways >= 2){
		num_ways += cur_ways - 1;
	}
    assert(cur_ways != 3);
}

