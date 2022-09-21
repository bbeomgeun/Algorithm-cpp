#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, a, b, c, from, to, e, answer;
vector<pii> v[10001];

bool compare(pii a, pii b) {
	return a.second > b.second;
}

bool BFS(int from, int to, int limit) {
	queue<int> q;
	int check[10001] = { false, };
	q.push(from);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == to) {
			return true;
		}

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int dis = v[x][i].second;

			if (dis >= limit && !check[nx]) {
				check[nx] = true;
				q.push(nx);
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		e = max(e, c);
	}

	for (int i = 0; i < 10001; i++) {
		sort(v[i].begin(), v[i].end(), compare);
	}
	cin >> from >> to;

	int start = 1;
	while (start <= e) {
		int mid = (start + e) / 2;
		if (BFS(from, to, mid)) {
			answer = mid;
			start = mid+1;
		}
		else {
			e = mid-1;
		}
	}
	cout << answer;
}