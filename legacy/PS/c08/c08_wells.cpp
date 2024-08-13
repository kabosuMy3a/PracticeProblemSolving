#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>

#define OUT_MAX 100000

std::pair<double, double> villages_in_out[10000] ;

int main(){

	int N ; int D ;
	std::cin >> N >> D ;
	for(int i = 0 ; i < N ; i++){
		int x ; int y;
		std::cin >> x >> y;
		double x_dist = sqrt(pow(D,2) - pow(y,2));
		std::pair<double, double> v = std::make_pair(x - x_dist, x + x_dist);
		villages_in_out[i] = v ; 
	}
	
	std::sort(villages_in_out, villages_in_out + N);

	double out_min = OUT_MAX; 
	int num_wells = 0 ;
	for(int i = 0 ; i < N ; i++){
		std::pair <double, double> v = villages_in_out[i];
		double in = v.first ;
		double out = v.second ;

		if(out_min > out) out_min = out ;

		if(out_min == in) {
			out_min = OUT_MAX ;
			num_wells++ ;
			continue ;
		} 

		if(i == N-1){
			num_wells++ ;
			continue ;
		}

		double next_in = villages_in_out[i+1].first;
		if(out_min == next_in){
			out_min = OUT_MAX ;
			num_wells++ ;
			i += 1; 
		} else if(out_min < next_in){
			out_min = OUT_MAX ;
			num_wells++;
		}
	}

	std::cout << num_wells << std::endl; 

	return 0 ;

}