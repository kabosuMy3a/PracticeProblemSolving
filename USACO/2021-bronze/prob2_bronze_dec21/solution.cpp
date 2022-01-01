#include <iostream>
#include <vector>
#include <chrono>

int main() {

	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	std::ios_base::sync_with_stdio(0x0); 
	std::cin.tie(0x0);

	int N;
	std::cin >> N;
	std::vector<int> p(N + 1), t(N + 1), d(N + 2);
	for (int i = 1; i <= N; ++i)
		std::cin >> p[i];
	for (int i = 1; i <= N; ++i)
		std::cin >> t[i];
	for (int i = 1; i <= N; ++i)
		d[i] = p[i] - t[i];
	long long ans = 0;
	for (int i = 0; i <= N; ++i)
		ans += abs(d[i] - d[i + 1]);
	std::cout << ans / 2 << "\n";
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::milliseconds milliSec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << milliSec.count() << std::endl;
	return 0;

}
