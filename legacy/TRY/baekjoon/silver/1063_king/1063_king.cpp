#include <iostream>
#include <cstring>
#include <utility>

std::pair<int, int> move(std::string s){
	std::pair<int, int> rt = {0,0};
	for(auto c : s){
		if(c == 'R'){
			rt.second += 1 ; 
		} else if(c == 'L'){
			rt.second -= 1 ;
		} else if(c == 'B'){
			rt.first += 1 ;
		} else if(c == 'T'){
			rt.first -= 1 ;
		} 
	}
	return rt ;
}


int main(){
	
	std::string king, rock ; std::cin >> king >> rock ;
	int N ; std::cin >> N ;
	int c = king[0] - 'A' ;
	int r = king[1] - '0' ;
	r = r + (8 + (r * -2)) ;
	std::pair<int, int> pos_king = {r,c};
	c = rock[0] - 'A';
	r = rock[1] - '0';
	r = r + (8 + (r * -2)) ;
	std::pair<int ,int> pos_rock = {r,c};

	for(int i = 0 ; i < N ; i++){
		std::string command ; std::cin >> command ;
		std::pair<int,int> next = move(command);
		std::pair<int,int> next_king 
			= {pos_king.first + next.first, pos_king.second + next.second};
		if(next_king.first < 0 || next_king.first >= 8) continue ;
		if(next_king.second < 0 || next_king.second >= 8) continue ;
		if(next_king.first == pos_rock.first && next_king.second == pos_rock.second){
			std::pair<int,int> next_rock 
				= {pos_rock.first + next.first, pos_rock.second + next.second} ;
			if(next_rock.first < 0 || next_rock.first >= 8) continue ;
			if(next_rock.second < 0 || next_rock.second >= 8) continue ;
			pos_rock = next_rock ;
		}
		pos_king = next_king ;

	}
	
	char kk = pos_king.second + 'A';
	char rr = pos_rock.second + 'A';
	c = pos_king.first - (8 + (-2 * (8 - pos_king.first)));
	std::cout << kk << c << "\n";
	c = pos_rock.first - (8 + (-2 * (8 - pos_rock.first)));
	std::cout << rr << c << "\n";

	return 0; 
}