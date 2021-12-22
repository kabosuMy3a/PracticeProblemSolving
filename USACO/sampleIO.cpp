#include <fstream>

int main() {
	std::ifstream fin("problemname.in");
	std::ofstream fout("problemname.out");
	std::ios_base::sync_with_stdio(0x0); 
	std::cin.tie(0x0);
	int a; int b; int c;
	fin >> a >> b >> c;
	fout << "The sum of these three numbers is " << a + b + c << "\n";
}