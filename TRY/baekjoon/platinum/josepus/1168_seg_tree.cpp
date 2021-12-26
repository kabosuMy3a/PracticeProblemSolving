#include <iostream>

int seg[262400] ;
int N, K ;

int construct_seg(int s, int e, int node){
	if(s == e){
		return seg[node] = 1 ;
	} else {
		int m = (s+e)/2 ;
		int l = construct_seg(s, m, node * 2) ;
		int r = construct_seg(m+1, e, node * 2 + 1) ;
		return seg[node] = l + r ;
	}
}

int get_kth_index_in_seg(int s, int e, int node, int k){
	seg[node] -= 1;
	if(s == e){
		return s ; //1 ~ N, origin idx, leaf node
	} else {
		int m = (s+e)/2 ;
		if(seg[node * 2] >= k){
			/* go to left */
			return get_kth_index_in_seg(s, m, node * 2, k);
		} else {
			/* go to right */
			int right_k = k - seg[node * 2];
			return get_kth_index_in_seg(m+1, e, node * 2 + 1, right_k);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(0x0);
	std::cout.tie(0x0);
	std::cin >> N >> K ;
	if(N == 1){
		std::cout << "<1>" <<"\n";
		return 0; 
	}
	construct_seg(1, N, 1);

	int prev = get_kth_index_in_seg(1, N, 1, K) ;	
	std::cout << "<" << prev << ", " ;
	for(int i = 1 ; i < N ;i++){
		int cur = (prev + K - 1) % (N-i);
		if(cur == 0) cur = N-i ;
		std::cout << get_kth_index_in_seg(1, N, 1, cur) ;
		if(i != N-1) std::cout << ", " ;
		prev = cur ;
	}

	std::cout << ">\n" ;
	return 0;
}