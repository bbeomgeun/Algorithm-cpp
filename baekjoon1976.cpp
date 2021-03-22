#include <iostream>
#include <vector>
using namespace std;

int n, m, num, from, to, flag;
int parent[201];
vector<int> v;

int getParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a > b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> flag;
			if (flag) {
				unionParent(i, j);
			}
		}
	}

	int r = 0;
	for (int i = 0; i < m; i++) {
		cin >> from;
		if (!r)
			r = getParent(from);
		else {
			if (r != getParent(from)) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}