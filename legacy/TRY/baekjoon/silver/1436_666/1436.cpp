#include <iostream>
#include <string>

int main(){
    int N ; std::cin >> N ; 
    int cur = 0 ; int num = 665 ;
    while(1){
        num++;
        int temp = num ;
	while(temp > 0){
		if(temp % 1000 == 666){
			cur++ ;
			break ;
		} else {
			temp /= 10 ;
		}	
	}

        if(cur == N){
            std::cout << num << "\n";
            exit(0);
        }
    }
    
    return 0 ;
}
