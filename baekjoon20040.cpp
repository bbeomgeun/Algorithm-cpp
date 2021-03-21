#include <iostream>
#include <algorithm>
using namespace std;

int parent[500001], n, m, from, to, answer;

int getParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
}

bool unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);

	if (x == y)
		return true;
	else {
		if (x > y) {
			parent[x] = y;
		}
		else
			parent[y] = x;
	}
	return false;
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0;  i < m; i++) {
		cin >> from >> to;
		if (unionParent(from, to) && answer == 0)
			answer = i + 1;
	}

	cout << answer;
}