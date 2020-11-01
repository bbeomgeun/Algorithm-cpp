#include <iostream>
using namespace std;

int parent[1000001], n, m, flag,x, y;

int findParent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = findParent(parent[x]);
}

void merge(int x, int y) {
	x = findParent(x);
	y = findParent(y);
	if (x >= y) {
		parent[x] = y;
	}
	else {
		parent[y] = x;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> flag >> x >> y;
		if (flag == 0) {
			merge(x, y);
		}
		else if (flag == 1) {
			if (findParent(x) == findParent(y))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}