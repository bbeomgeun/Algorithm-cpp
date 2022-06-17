#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<pair<pii, int>> v;
int n, weight;
int parent[1001];
long long answer;

bool compare(pair<pii, int>& a, pair<pii, int>& b) {
	return a.second < b.second;
}

int getParent(int a) {
	if (a == parent[a])
		return a;
	else {
		return parent[a] = getParent(parent[a]);
	}
}

bool find(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b)
		return false;
	else
		return true;
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> weight;
			if (i == j)
				continue;
			v.push_back({ {i, j}, weight });
		}
		parent[i] = i;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		int from = v[i].first.first;
		int to = v[i].first.second;
		int weight = v[i].second;

		if (find(from, to)) {
			unionParent(from, to);
			answer += weight;
		}
	}

	cout << answer;
}