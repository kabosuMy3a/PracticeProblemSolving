#include <iostream>

int H, W, N, M ;

int main(){

	std::cin >> H >> W >> N >> M ;
	int w_num = (W -1) / (M + 1) + 1 ;
	int h_num = (H -1) / (N + 1) + 1;

	std::cout << w_num * h_num << "\n";

	return 0 ;
}