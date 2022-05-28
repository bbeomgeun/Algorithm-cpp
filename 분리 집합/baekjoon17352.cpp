#include <iostream>
#include <unordered_set>

using namespace std;

int n, from, to;
int parent[300001];
unordered_set<int> s;

int getParent(int x) {
	if (x == parent[x]) {
		return parent[x];
	}
	else {
		return parent[x] = getParent(parent[x]);
	}
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n-2; i++) {
		cin >> from >> to;
		unionParent(from, to);
	}

	for (int i = 1; i <= n; i++) {
		getParent(i);
	}

	for (int i = 1; i <= n; i++) {
		s.insert(parent[i]);
	}
	
	for (auto k : s) {
		cout << k << " ";
	}

}