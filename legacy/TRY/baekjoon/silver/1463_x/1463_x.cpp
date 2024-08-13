#include <iostream>

int N ; int ans = 0 ;
int a[1000001];

int main(){
    std::cin >> N ;

    a[1] = 0; a[2] = 1; a[3] = 1;     
    for(int i = 4 ; i <= N ; i++){
        int cur_min = a[i-1] + 1;
        if((i % 3 == 0) && (cur_min > a[i/3] + 1))
            cur_min = a[i/3] + 1;   
        if((i % 2 == 0) && (cur_min > a[i/2] +1))
            cur_min = a[i/2] + 1;
        a[i] = cur_min;
    }

    std::cout << a[N] << "\n";
    
    return 0;
}