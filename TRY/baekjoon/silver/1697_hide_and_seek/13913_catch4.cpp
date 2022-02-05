#include <iostream>
#include <queue>
#include <vector>

int JOHN, COW ;
int catch_time[100001];
int prev[100001] ;

int main(){

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
    prev[JOHN] = -1 ;
	
	while(!bfs_q.empty()){
		int cur = bfs_q.front();
		bfs_q.pop();

		int next = cur - 1;
		if(next >= 0 && catch_time[next] == -1){
			bfs_q.push(next);
			catch_time[next] = catch_time[cur] + 1;
            prev[next] = cur ;
		}

		next = cur + 1;
		if(next <= COW + 1 && catch_time[next] == -1){
			bfs_q.push(next);
			catch_time[next] = catch_time[cur] + 1;
            prev[next] = cur;
		}

		next = cur * 2;
		if(next <= COW + 1 && catch_time[next] == -1){
			bfs_q.push(next);
			catch_time[next] = catch_time[cur] + 1;
            prev[next] = cur ;
		}
	}

	std::cout << catch_time[COW] << "\n";
    std::vector<int> v ; v.push_back(COW); int p = COW ;
    while(1){ 
        if(prev[p] == -1) break; 
        v.push_back(prev[p]);
        p = prev[p];
    }
    for(auto it = v.rbegin() ; it != v.rend() ; it++){
    	std::cout << *it << " ";
    }
    std::cout <<"\n";

	for(int i = 0 ; i <= COW + 1 ; i++){
		std::cout << catch_time[i] << " ";
	}
	std::cout << "\n";
	
	
	return 0 ;
}