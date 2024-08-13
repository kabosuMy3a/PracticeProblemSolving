#include <iostream>

struct Node {
	int key ;
	Node * parent; 
	Node * left ;
	Node * right ;
} ;


void post_traverse(Node * cur){
	if(cur->left != 0x0) post_traverse(cur->left);
	if(cur->right != 0x0) post_traverse(cur->right);
	std::cout << cur->key << "\n";
	delete[] cur; 
}

int main(){

	Node * root = 0x0 ; Node * cur = 0x0 ; int num ;
	while(std::cin >> num){
		if(root == 0x0){
			Node * tmp = new Node();
			tmp->key = num ; tmp->parent = 0x0 ; tmp->left = 0x0 ; tmp->right = 0x0 ;
			root = tmp ;
			cur = root ;
		} else {
			Node * next = new Node();
			next->key = num ; next->parent = cur ; next->left = 0x0; next->left = 0x0 ;
			if(num < cur->key){
				cur->left = next ;
				cur = cur->left;
			} else {
				while(cur->parent != 0x0 && cur->parent->key < num) cur = cur->parent ;
				while(cur->right != 0x0 && cur->right->key < num) cur = cur->right ;
				next->parent = cur ; 
				if(cur->right == 0x0){
					cur->right = next;
				} else {
					Node * tmp = cur->right ;
					tmp->parent = next ; 
					next->right = tmp ;
					cur->right = next ;
				}
				cur = cur->right ;
			}	 
		}
	}

	post_traverse(root);

	return 0;
}