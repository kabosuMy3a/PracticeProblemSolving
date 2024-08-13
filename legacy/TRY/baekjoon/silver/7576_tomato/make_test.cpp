#include <fstream>

int main(){

	std::ofstream fout("11.txt");
	fout << "100 100" << "\n";
	for(int i = 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 100 ; j++){
			fout << 0 << " " ;
		}
		fout << "\n" ;
	}

	return 0;
}
