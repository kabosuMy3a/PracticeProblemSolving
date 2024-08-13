#include <iostream>

int main(){
	FILE * fp ;

	fp = fopen("aa.txt","a");
	
	fprintf(fp, "499\n");
	for(int i = 0 ; i < 499 ; i++){
		fprintf(fp, "10000 ");
	}
	fclose(fp);
	return 0;
}
