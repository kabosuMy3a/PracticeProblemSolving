#include <iostream> 

int N ; long long rocks[100] ;
int num_single_rocks = 0 ; 

void win(int is_formal){
    if(is_formal) std::cout << "koosaga\n" ;
    else std::cout << "cubelover\n" ;
    exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin >> N ; long long ans ;
	for(int i = 0 ; i < N ; i++){		
		std::cin >> rocks[i];
	    if(rocks[i] == 1) num_single_rocks++ ;		
	}
    if(num_single_rocks == N){
        if(N % 2 == 0) win(1);
        else win(0) ;
    } else {
        if(num_single_rocks > 0 && num_single_rocks % 2 == 0){
            for(int i = 0 ; i < N ; i++){
                if(rocks[i] != 1){
                    rocks[i] = 1 ;
                    break; 
                }
            }
        }
        long long ans = rocks[0] ;
        for(int i = 1 ; i < N ; i++){
            ans ^= rocks[i] ;
        }
        if(ans == 0){
            win(0);
        } else {
            win(1);
        }
        
    }
    

    

	return 0 ;
}