#include <iostream>

int ans[100001];
int T ;

int get_ans(int cur){
	if(ans[cur] != 0) return ans[cur];
	
	int cur_ans = 0;
	cur_ans += get_ans(cur -1);
	cur_ans += get_ans(cur -2);
	cur_ans += get_ans(cur -3);

	return cur_ans ;
}

int main(){
    std::cin >> T ;
    
    ans[1] = 1; ans[2] = 2 ; ans[3] = 4;
    for(int i = 4 ; i <= 100000 ; i++){
        ans[i] = get_ans(i);
    }
    
    
    for(int t = 0 ; t < T ; t++){
        int a ; std::cin >> a;
        std::cout << ans[a] << "\n";
    } 
    
    return 0 ;
}