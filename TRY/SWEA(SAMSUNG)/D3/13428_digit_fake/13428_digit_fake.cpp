#include <iostream>
#include <cstring>

int main(int argc, char** argv)
{
    
	int test_case;
	int T;
	std::cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		std::string s ; std::cin >> s ;
        int max_nums[9] ; int idx = 0 ;
        int min_nums[9] ;
        for(auto c : s){
        	int a = c - '0' ;
            max_nums[idx] = a ;
            min_nums[idx++] = a ;
        }

        for(int i = 0 ; i < idx ; i++){
            int flag = 0; 
            int cur = max_nums[i];
            int cur_idx = i ;
            for(int j = i + 1 ; j < idx ; j++){
            	if(cur <= max_nums[j]){
                    cur = max_nums[j] ;
                    cur_idx = j ;
                    if(cur != max_nums[i]) flag = 1; 
                }
            }
            if(flag){
                max_nums[cur_idx] = max_nums[i];
                max_nums[i] = cur ;
                break ; 
            }
        }
        
         for(int i = 0 ; i < idx ; i++){
            int flag = 0;
            int cur = min_nums[i];
            int cur_idx = i ;
            for(int j = i + 1 ; j < idx ; j++){
            	if(cur >= min_nums[j]){
                    if(i == 0 && min_nums[j] == 0) continue ;  
                    cur = min_nums[j];
                    cur_idx = j;
                    if(cur != min_nums[i]) flag = 1;
                }
            }
            if(flag){
                min_nums[cur_idx] = min_nums[i] ;
                min_nums[i] = cur ;
                break ; 
            }
        }

        std::cout << "#" << test_case << " ";
        for(int i = 0 ; i < idx ; i++) std::cout << min_nums[i] ;
        std::cout << " ";
        for(int i = 0 ; i < idx ; i++) std::cout << max_nums[i] ;
        std::cout << "\n";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}