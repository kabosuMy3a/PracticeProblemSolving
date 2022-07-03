#include <iostream>
#include <map>

std::map<int,int> m ;


int main(){
	
	int N ; std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		int a ; std::cin >> a;
		if(m.find(a) == m.end()){
			m.insert({a,1});
		} else {
			m[a] += 1 ;
		}
	}
	
	int M ; std::cin >> M ;
	for(int i = 0 ; i < M ; i++){
		int a; std::cin >> a;
		std::cout << m[a] << " ";
	}


	return 0 ; 
}