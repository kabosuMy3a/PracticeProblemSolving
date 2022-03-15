#include <iostream>
#include <vector>

std::vector<int> match_time_to_piece[100]; //time;
int processed[101]; //piece
int matched_time[101]; //piece

void get_test(int N, int M){
	for(int i = 0 ; i < 100 ; i++) match_time_to_piece[i].clear();
	for(int i = 1 ; i <= N ; i++) matched_time[i] = -1 ;
	for(int m = 0 ; m < M ; m++){
		int t1, t2, P ; std::cin>> t1 >> t2 >> P ;
		for(int p = 0 ; p < P ; p++){
			int no ; std::cin >> no ;
			for(int i = t1 ; i < t2 ; i++) match_time_to_piece[i].push_back(no);
		}
	}
}

bool match(int cur_time){
	for(auto available_piece : match_time_to_piece[cur_time]){
		if(processed[available_piece]) continue ;
		processed[available_piece] = 1 ;
		if(matched_time[available_piece] == -1 || match(matched_time[available_piece])){
			matched_time[available_piece] = cur_time ;
			return 1 ;
		}
	}
	return 0 ;
}

int main(){
	std::ios_base::sync_with_stdio(0x0) ; std::cin.tie(0x0) ;
	int T ; std::cin >> T ;	
	for(int t = 0 ; t < T ; t++){
		int N, M ; std::cin >> N >> M ;
		get_test(N, M); int num_get_pieces = 0 ; int i ;
		for(i = 0 ; i < 100 ; i++){
			for(int j = 1 ; j <= N ; j++) processed[j] = 0 ;
			if(match(i)) num_get_pieces += 1 ;
			if(num_get_pieces == N) break;
		}
		/*
		std::cout << num_get_pieces << "\n";
		for(int i = 1 ; i <= N ; i++){
			std::cout << i << "<- "<< matched_time[i] << "\n";
		}*/
		(num_get_pieces == N) ? std::cout << i + 1 : std::cout << -1 ;
		std::cout << "\n";
	}

	return 0 ;
}