#include <fstream>

int main(){
	std::ofstream fout("kabosumy3a.out");
	fout << 100000 <<"\n";
	for(int i = 0 ; i < 100000 ; i++){
		fout << i % 10000 << " ";
	}
	fout << "\n";
	for(int i = 0 ; i < 100000 ; i++){
		fout << 0 << " " ;
	}

	return 0;
}
