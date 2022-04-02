#include <string>
#include <vector>
#include <iostream>
#include <utility>

char grid[9][9];
int ans = 0 ; int r = 0, c ;

std::vector<std::pair<int,int>> pos_questions ;

int visited[9][9] ;


int next_r[4] = {0,1,0,-1}; int next_c[4] = {1,0,-1,0};
int dfs2(char ch, int cur_r, int cur_c){
	if(visited[cur_r][cur_c]) return 0  ;
	visited[cur_r][cur_c] = 1 ;

	int rst = 1 ;
	for(int i = 0 ; i < 4 ; i++){
		int nr = next_r[i] + cur_r ;
		int nc = next_c[i] + cur_c ;
		if(nr < 0 || nr > r) continue;
		if(nc < 0 || nc > c) continue;
		if(visited[nr][nc]) continue ;
		if(grid[nr][nc] != ch) continue ;
		rst += dfs2(ch, nr, nc);
	}
	return rst ;
}

int check(){

	int num_find = 0 ;
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			visited[i][j] = 0 ; 
		}
	}
	int ca = 0 ; int cb =0 ; int cc = 0 ;
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			if(!ca && grid[i][j] == 'a'){
				ca = 1 ;
				num_find += dfs2('a',i,j);
			} 
			if(!cb && grid[i][j] == 'b'){
				cb = 1 ;
				num_find += dfs2('b',i,j);
			}
			if(!cc && grid[i][j] == 'c'){
				cc = 1 ;
				num_find += dfs2('c',i,j);
			}
		}
	}
	if(num_find == r * c) return 1 ;
	else return 0 ;

}

void dfs(int idx){

	if(idx == pos_questions.size()){
		if(check()) ans++; 
		return ;
	}

	std::pair<int,int> cur = pos_questions[idx] ;
	char abc[3] = {'a','b','c'};

	for(int i = 0 ; i < 3 ; i++){
		grid[cur.first][cur.second] = abc[i]; 
		dfs(idx + 1);
	}
}

int main(){

	//
	std::vector<std::string> origin ;
	int N ; std::cin >> N ;
	for(int i = 0 ; i < N ; i++){
		std::string s ; std::cin >> s ;
		origin.push_back(s);
	}
	//

    for(auto s : origin){
        c = 0; 
        for(auto ch : s){
            grid[r][c] = ch ;
            if(ch == '?') pos_questions.push_back({r,c});            
            c++;
        }
        r++;
    }

    dfs(0);
    std::cout << ans << "\n";


	return 0 ;
}