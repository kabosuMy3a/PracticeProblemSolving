#include <iostream>

int cost[6] ;

int main(){

	if(cost[0] * 5 < cost[1]) cost[1] = cost[0] * 5 ;
	if(cost[1] * 2 < cost[2]) cost[2] = cost[1] * 2 ;
	if(cost[2] * 5 < cost[3]) cost[3] = cost[2] * 5 ;
	if(cost[3] * 2 < cost[4]) cost[4] = cost[3] * 2 ;
	if(cost[4] * 5 < cost[5]) cost[5] = cost[4] * 5 ;

 	ans += cost[5] * (money /= 500) ; money %= 500 ;
 	ans += cost[4] * (money /= 100) ; moeny %= 100 ;
 	ans += cost[3] * (money /= 50)  ; money %= 50  ;
 	ans += cost[2] * (money /= 10) ; money %= 10 ;
 	ans += cost[1] * (money /= 5) ; moeny %= 5 ;
 	ans += cost[0] * (money /= 1)  ; money %= 1  ;

	return 0;
}