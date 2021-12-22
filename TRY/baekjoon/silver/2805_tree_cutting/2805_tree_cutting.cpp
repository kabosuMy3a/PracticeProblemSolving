#include <iostream>
#include <algorithm>

int num_trees ;
int need_size ;

long long trees[1000001];
long long max_enable_tree_when_cutting_border[1000000];

bool compare(int a, int b){
   return b < a ; 
}

int main(){
    std::cin >> num_trees ;
    std::cin >> need_size ;
    for(int i = 0 ; i < num_trees ; i++){
        int a ; std::cin>> a;
        trees[i] = a ;
    }
    trees[num_trees] = 0 ;
    std::sort(trees, trees + num_trees + 1, compare);

    
    long long accumulated = 0 ; long long i ; 
    for(i = 0 ; i < num_trees ; i++){
        long long cur = trees[i]; long long next = trees[i+1];
        long long num_cutting_tree = i+1;
        accumulated += (cur - next) * num_cutting_tree ;
        max_enable_tree_when_cutting_border[i] = accumulated ;

        if(need_size <= accumulated) break ; 
    } 

    long long h ;
    need_size -= max_enable_tree_when_cutting_border[i-1] ;
    h = trees[i] ;
    long long x  = need_size / (i+1) ; if((need_size % (i+1)) != 0) x += 1 ;
    h -= x ;


    std::cout << h << std::endl; 
    
    return 0 ;
}