#include <iostream>
#include <vector>
#include <random>


long long solve1(std::vector<long long>& numbers){

	int size = numbers.size();
	
	long long max = 0 ;
	for(int i = 0 ; i < size ; i++){
		for(int j = i+1 ; j < size ; j++){
			long long now = numbers[i] * numbers[j] ; 
			max = (max > now) ? max : now ;
		}
	}

	return max ;

}

long long solve2(std::vector<long long>& numbers){

	int size = numbers.size();

	long long first = 0;
	long long second = 0;

	for(int i = 0 ; i < size ; i++){
		long long now = numbers[i];
		if(now >= first){
			second = first ;
			first = now ;
		} else if(now > second){
			second = now ;
		}
	}

	return first * second ;

}


int main(){

	std::random_device rd ;
	std::mt19937 gen(rd()) ;
	std::uniform_int_distribution<int> dis(2, 100);

	int testTime = dis(gen);
	

	for(int k = 0 ; k  < testTime ; k++){
		int n = dis(gen);
		std::vector<long long> numbers(n);


		std::uniform_int_distribution<long long> num_dis(0, 1000000000);

		for(int i = 0 ; i < n ; i++){
			numbers[i] = num_dis(gen);
		}


		if(solve1(numbers) == solve2(numbers)){
			std::cout << "CLEAR" << std::endl; 
		} else {

			std::cout << "WRONG" << std::endl;
		}

	}	


	/*

	int n ;
	std::cin >> n ;

	std::vector<long long> numbers(n);

	for(int i = 0 ; i < n ; i++){
		std::cin >> numbers[i];
	}

	solve2(numbers);
	*/

	return 0 ;
}