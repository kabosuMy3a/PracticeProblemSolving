#include <iostream>
#include <vector>

int main(){
    int n ;
    std::cin >> n;
    
    std::cout << std::fixed ;
    std::cout.precision(3);
    
    for(int i = 0 ; i < n ; i++){
        int num;
        std::cin >> num;
        int sum = 0 ;
        double avg = 0 ;
        std::vector<int> v ; 
        for(int j = 0 ; j < num ; j++){
            int score ;
            std::cin >> score ;
            sum += score ;
            v.push_back(score);
        }
        avg = (double)sum / (double)num ;
        int high = 0 ;
        for(int j = 0 ; j < num ; j++){
            if((double)v[j] > avg)
                high++;
        }
        std::cout << (double) high / (double) num * (double) 100 << "%" <<std::endl;
    }
    

    
    return 0;
}