#include <iostream>

int N ; 
int seg[1<<22] ;

int construct_seg(int s, int e, int node){
	if(s==e){
		return seg[node] = 0 ;
	} else {
		int m = (s+e)/2 ;
		construct_seg(s, m, node * 2);
		construct_seg(m+1, e, node * 2 + 1);
		return 0 ;
	}
}

void insert_seg(int s, int e, int node, int x){
	seg[node] += 1;
	if(s==e){
		return ;
	} else{
		int m = (s+e)/2 ;
		if(x <= m){
			insert_seg(s, m, node * 2, x);
		} else{
			insert_seg(m+1, e, node * 2 + 1, x);
		}
	}
}

int delete_seg(int s, int e, int node, int k){
	seg[node] -= 1;
	if(s==e){
		return s ;
	} else {
		int m = (s+e)/2 ;
		if(k <= seg[node * 2]){
			return delete_seg(s, m, node * 2, k);
		} else {
			int right_k = k - seg[node * 2];
			return delete_seg(m+1, e, node * 2 + 1, right_k);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cin.tie(0x0); std::cout.tie(0x0);
	std::cin >> N ;
	int q_type ; int x_or_k ;
	construct_seg(1, 2000000, 1);
	for(int i = 0 ; i < N ; i++){
		std::cin >> q_type >> x_or_k ;
		if(q_type == 1){
			insert_seg(1, 2000000, 1, x_or_k);
		} else {
			int q_ans = delete_seg(1, 2000000, 1, x_or_k);
			std::cout << q_ans << "\n";
		}
	}
}
