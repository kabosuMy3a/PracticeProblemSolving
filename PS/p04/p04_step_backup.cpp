#include <iostream>
#include <cmath>
#include <cfloat>

typedef struct {
	long double x ;
	long double y ;

} Point ;

std::ostream& operator<<(std::ostream &o, const Point pp){
    return o  << pp.x << ", " << pp.y ;
}


Point p[2][1000000] = {0} ;
Point new_p[2000000] = {0} ;

long long p_sz[2] ;
long long new_p_sz = 0;

long long L ;
long long R ;

long double solution = 0 ;


void _init(){

	long double x_input ;
	long double y_input ;

	for(int k = 0 ; k < 2 ; k++){
		std::cin >> p_sz[k] ;
		for(long long i = 0 ; i < p_sz[k] ; i++){
			std::cin >> x_input >> y_input ;
			Point pp = {x_input, y_input} ;
			p[k][i] = pp ;
		}
	}

	std::cin >> L >> R ;
}


long double ld_max(long double a, long double b){
	long double c ;
	if(a >= b){
		c = a;
	}
	else {
		c = b;
	}
	return c ;
}

long double ld_min(long double a, long double b, int * smaller){
	long double c ;
	if(a <= b){
		c = a;
		*smaller = 0;
	}
	else {
		c = b;
		*smaller = 1;
	}
	return c ;	
}


void _merge(){


 	long double f_prev = 0;
 	long double g_prev = 0;
 	long long f_idx = 0;
 	long long g_idx = 0;

 	int fun_num ;
 	long double cur ;

 	long long new_p_idx = 0 ;
 	int flag1 =0;
 	int flag2 =0;


 	while(1){

 		if(flag1 && flag2){
 			break; 
 		} else if(flag1){
 			cur = p[1][g_idx].x;
 			fun_num = 1 ;
 		} else if(flag2){
 			cur = p[0][f_idx].x;
 			fun_num = 0;
 		} else {
			cur = ld_min(p[0][f_idx].x, p[1][g_idx].x, &fun_num);
		}


 		if(fun_num == 0){
 			long double f_val = p[0][f_idx].y ;
 			if(f_val > g_prev){
 				new_p[new_p_idx++] = {cur, f_val};
 			} else {
 				new_p[new_p_idx++] = {cur, g_prev};
 			}
	 		f_prev = f_val;

 			f_idx += 1;
 			if(f_idx == p_sz[0]){
 				flag1 = 1;
 			}
 		} else {
 			long double g_val = p[1][g_idx].y;

 			if(g_val > f_prev){
 				new_p[new_p_idx++] = {cur, g_val};
 			} else {
 				new_p[new_p_idx++] = {cur, f_prev};
 			}	
	 		g_prev = g_val;
	 			
 			g_idx += 1;
 			if(g_idx == p_sz[1]){
 				flag2 = 1;
 			}
 		}

  	}
  	new_p_sz = new_p_idx ;
}

void solve(){

	long long p_idx = 1 ;

	long double base = 10007 ;


	while(p_idx < new_p_sz){

		long long left = (long long)new_p[p_idx-1].x;
		long long right = (long long)new_p[p_idx].x;

		if(left -right == 0){
			p_idx+= 1;
			continue ;
		}

		long double yy = new_p[p_idx-1].y ;
		long long cnt = 0;

		for(long long i= left ; i < right ; i++){
			if(i >= L && i <= R){
					cnt += 1 ;
			}
		}

		int a = L < left ;
		int b = L > right ;

		solution += fmodl(fmodl(cnt,base) * fmodl(yy,base), base);

		//std::cout << L << "," << left << a << " " << b << std::endl;
		std::cout << "p_idx: "<< p_idx << " ~ " << left << ", " << right << std::endl;
		std::cout << "p_idx: "<< p_idx << " ~ " << cnt << std::endl; 
		p_idx++;

	}

	long long last = (long long)new_p[p_idx-1].x;
	long long cnt = 0;

	if(last >= L){
		if(last <= R){
			cnt = R - last + 1 ;
		}
	} else {
		cnt = R - L + 1;
	}
	solution += fmodl(fmodl(cnt,base) * fmodl(new_p[p_idx-1].y, base), base);

	solution = fmodl(solution, base);

}
 
int main(){

	_init();
	_merge();
	solve();

	
	for(int i = 0 ; i < p_sz[0] ; i++){
		std::cout << p[0][i] << std::endl ;
	}
	std::cout << std::endl; 

	for(int i = 0 ; i < p_sz[1] ; i++){
		std::cout << p[1][i] << std::endl ;
	}
	
	std::cout << std::endl; 


	for(int i = 0 ; i < new_p_sz ; i++){
		std::cout << new_p[i] <<  std::endl;
	}

	std::cout << std::endl;
	
	
	std::cout << solution << std::endl;
	
	
	return 0 ;

}