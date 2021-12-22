#include <iostream> 

int main(){
    int i = 1;
    while(1){
        int a; 
        std::cin >> a;
        if(a == 0)
            break; 
        for(int j = 0 ; j < a ; j++){
		scanf("%*d");
	} 
        printf("Case %d: Sorting... done!\n", i++);
    }
   
    return 0 ;
}
