#include <iostream>
    
int main(){
    int N ; std::cin >> N ;
    for(int i = 0 ; i < N ; i++){
        int H, W, target ;
        std::cin >> H >> W >> target ;
        int a = target / H ;
        int b = target % H ;
        if(b == 0){
		 a -= 1 ;
		 b += H ;
	} 
      
        std::cout << b * 100 + a + 1  << "\n" ;
    }
    return 0;
}
