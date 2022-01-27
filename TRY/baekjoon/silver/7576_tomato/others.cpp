#include<iostream>
using namespace std;
int main() {
	int m, n;
	cin >> n >> m;
	//표 생성.
	short** boxes[2];
	boxes[0] = new short* [m];
	for (short i = 0; i < m; i++)
		boxes[0][i] = new short[n] {0, };
	//입력.
	int count = 0;
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			cin >> boxes[0][y][x];
			if (boxes[0][y][x] != -1) count++;
		}
	}
	//깊은 복사
	boxes[1] = new short* [m];
	for (int y = 0; y < m; y++) {
		boxes[1][y] = new short[n];
		for (int x = 0; x < n; x++)
			boxes[1][y][x] = boxes[0][y][x];
	}
	int count_2 = 0, day = 0;
	short** tmpBox;
	while (true)
	{
		if (day > 2 * m + 2 * n - 4) { day = -1; break; }
		count_2 = 0;
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				if (boxes[0][y][x] == 1) {
					count_2++;
					if (x + 1 < n) boxes[1][y][x + 1] = boxes[0][y][x + 1] == 0 ? 1 : boxes[0][y][x + 1];
					if (x - 1 >= 0) boxes[1][y][x - 1] = boxes[0][y][x - 1] == 0 ? 1 : boxes[0][y][x - 1];
					if (y + 1 < m) boxes[1][y + 1][x] = boxes[0][y + 1][x] == 0 ? 1 : boxes[0][y + 1][x];
					if (y - 1 >= 0) boxes[1][y - 1][x] = boxes[0][y - 1][x] == 0 ? 1 : boxes[0][y - 1][x];
				}
			}
		}
		if (count_2 == count) break;
		day++;
		tmpBox = boxes[1];
		boxes[1] = boxes[0];
		boxes[0] = tmpBox;
	}
	cout << day;
}