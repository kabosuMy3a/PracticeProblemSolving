#include <iostream>
#include <vector>
#include <utility>
int N ;
std::pair<int,int> tree[26] ;

void preorder(int cur){
	std::cout << (char)(cur + 'A') ;
	if(tree[cur].first != -1) preorder(tree[cur].first);
	if(tree[cur].second != -1) preorder(tree[cur].second);
}

void inorder(int cur){
	if(tree[cur].first != -1) inorder(tree[cur].first);
	std::cout << (char)(cur + 'A') ;
	if(tree[cur].second != -1) inorder(tree[cur].second);
}

void postorder(int cur){
	if(tree[cur].first != -1) postorder(tree[cur].first);
	if(tree[cur].second != -1) postorder(tree[cur].second);
	std::cout << (char)(cur + 'A') ;
}

int main(){
	
	std::cin >>  N;
	for(int i = 0 ; i < N ; i++){
		char n ; std::cin >> n ;
		char l, r ; std::cin >> l >> r ;
		int node = n - 'A';
		int left = l - 'A';
		int right = r - 'A';

		std::pair<int,int> tmp ;
		if(l != '.'){
			tmp.first = left ;
		} else {
			tmp.first = -1 ;
		}
		if(r != '.'){
			tmp.second = right ;
		} else {
			tmp.second = -1 ;
		}
		tree[node] = tmp ;
	}

	preorder(0);
	std::cout << "\n";
	inorder(0);
	std::cout <<"\n";
	postorder(0);
	std::cout << "\n";

	return 0 ;
}