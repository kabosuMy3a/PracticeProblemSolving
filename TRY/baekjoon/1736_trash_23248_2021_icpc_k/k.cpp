#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, int> a, const std::pair<int, int> b){
	if(a.first == b.first)
		return a.second < b.second ;
	else return a.first < b.first ;
}

int main(){

	std::vector<std::pair<int,int>> ts ;
	std::vector<std::pair<int,int>> thr ;

	int m ; int n ;
	std::cin >> m  >> n;

	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= n ; j++){
			int a;
			std::cin >> a;
			if (a == 1) 
				ts.push_back(std::make_pair(i,j));
	    }
	}

	//icpc version input needs sorting //
	//std::sort(ts.begin(), ts.end(),compare);

	for(int i = 0 ; i < ts.size(); i++){
		std::pair<int, int> cur = ts[i] ;
		std::pair<int, int> last ;

		int need_new_thr = 1 ;
		for(int j = 0 ; j < thr.size() ; j++){
			last = thr[j] ;
			if(last.first <= cur.first && last.second <= cur.second){
				thr[j] = cur ;
				need_new_thr = 0;
				break ; 
			}
		}

		if(need_new_thr){
			last = cur ;
			thr.push_back(last);
		}

	}

	std::cout << thr.size() << std::endl;

	return 0 ;

}
