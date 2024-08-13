#include <iostream>
#include <stack>
#include <string>

int main(){

	while(1){		

		std::stack<char> st ;
		std::string s; 
		std::getline(std::cin, s);

		if(s == ".") break;

		int flag = 0 ;

		for(auto c : s){
			if(c == '[' || c =='(') st.push(c);
			if(c == ']'){

				if(st.empty() || st.top() != '['){
					std::cout << "no\n";
					flag = 1 ;
					break; 
				}
				st.pop();
			}
			if(c == ')'){
				if(st.empty() || st.top() != '('){
					std::cout << "no\n";
					flag = 1; 
					break;
				} 
				st.pop();
			}
		}


		if(flag) continue ;
		if(st.empty()) std::cout << "yes\n";
		else std::cout << "no\n";

	}



	return 0;
}