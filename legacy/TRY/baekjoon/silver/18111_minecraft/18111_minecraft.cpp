#include <iostream>

int N ; int M ; long long B ;
int house_map[500][500];
int min_height = 256 ; int max_height = 0 ;

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0);
	std::cin >> N >> M >> B ;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			int a ; std::cin >> a ;
			house_map[i][j] = a ;
			if(min_height > a) min_height = a;
			if(max_height < a) max_height = a;
		}
	}

	int min_time = 1234567801 ; int ans_height = 0 ;
	for(int i = min_height ; i <= max_height ; i++){
		int block_need = 0 ; long long cur_inven = B ;
		int time_need = 0 ;
		for(int j  = 0 ; j < N ; j++){
			for(int k = 0 ; k < M ; k++){
				if(house_map[j][k] < i){
					int height_dist = i - house_map[j][k];
					block_need += height_dist ;
					time_need += height_dist ; 
				} else {
					int height_dist = house_map[j][k] - i ;
					cur_inven += height_dist ;
					time_need += 2 * height_dist ;
				}
			}
		} 
		if(cur_inven < block_need) continue ;
		if(time_need <= min_time){
			if(ans_height < i) ans_height = i ;
			min_time = time_need ;
		}
	}

	std::cout << min_time << " " << ans_height << "\n" ;

	return 0;
}

