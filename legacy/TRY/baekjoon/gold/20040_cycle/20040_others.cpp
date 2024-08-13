#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define SIZE 500111
#define INF 987654321
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m;
struct UF {
	int parent[SIZE];
	UF() {
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}
	int find(int idx) {
		if (parent[idx] == idx)return idx;
		else return parent[idx] = find(parent[idx]);
	}
	bool is_union_(int v1, int v2) {
		v1 = find(v1), v2 = find(v2);
		if (v1 == v2) return true;
		else return false;
	}
	void merge(int v1, int v2) {
		v1 = find(v1), v2 = find(v2);
		if (v1 < v2) parent[v2] = v1;
		else parent[v1] = v2;
	}
};
int main() {
	fastio;
	cin >> n >> m;
	UF u;
	int ret = 0;
	for (int i = 1; i <= m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		if (!u.is_union_(v1, v2)) {
			u.merge(v1, v2);
		}
		else {
			ret = i;
			break;
		}

	}
	cout << ret;

	return 0;
}