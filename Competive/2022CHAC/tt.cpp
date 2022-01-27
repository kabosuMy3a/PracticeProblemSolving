#include <fstream>

int main(){
	
	std::ofstream fout("c5.txt");
	fout << 1000 << " " << 1000 << "\n";
	for(int i = 0 ; i < 1000 ; i++){
		for(int j = 0 ; j < 1000 ; j++){
			fout << 1 << " ";
		}
		fout << "\n" ;
	}
	return 0;
}