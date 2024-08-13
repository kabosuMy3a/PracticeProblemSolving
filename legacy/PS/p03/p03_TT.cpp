#include <iostream>

long long bags_classified_by_wegihts[100001] = {0} ;

int main(){

	int weight_max = 0 ;
	std::cin >> weight_max ;
	if(weight_max == 0){
		std::cout << 0 << std::endl ;
	}

	int bag_weight = 0 ;
	long long num_carrier = 0 ;

	while(std::cin >> bag_weight){
		if(bag_weight < 0 || bag_weight > weight_max)
			 continue ;
		bags_classified_by_wegihts[bag_weight] += 1;
	}

	int weight_half = weight_max / 2 ;

	long long bonus_bag = 0 ;

	for(int w = weight_max ; w > weight_half ; w-- ){
		
		int left_weight = weight_max - w ;
		bonus_bag += bags_classified_by_wegihts[left_weight];

		long long num_bags_same_weight = bags_classified_by_wegihts[w] ;

		if(num_bags_same_weight != 0){
			if(bonus_bag != 0){
				bonus_bag -= num_bags_same_weight ;
				if(bonus_bag < 0) 
					bonus_bag = 0 ;
			}
			num_carrier += num_bags_same_weight;
		}
	}

	if(weight_max % 2 == 0) 
		bonus_bag += bags_classified_by_wegihts[weight_half] ;

	if(bonus_bag > 0){
		num_carrier += bonus_bag / 2 ;
		num_carrier += bonus_bag % 2 ;
	}

	std::cout << num_carrier << std::endl ;

}