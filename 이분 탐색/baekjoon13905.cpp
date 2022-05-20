#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int n, m, s, e, from, to, k, answer, mx;
vector<pii> v[100001];

bool BFS(int s, int e, int limit) {
	int check[100001] = { false, };
	queue<int> q;
	q.push(s);
	check[s] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == e)
			return true;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int weight = v[x][i].second;

			if (!check[nx] && weight >= limit) {
				q.push(nx);
				check[nx] = true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> s >> e;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> k;
		v[from].push_back({ to, k });
		v[to].push_back({ from, k });
		mx = max(mx, k);
	}
	
	int left = 1;
	while (left <= mx) {
		int mid = (left + mx) / 2;

		if (BFS(s, e, mid)) {
			answer = mid;
			left = mid + 1;
		}
		else {
			mx = mid - 1;
		}
	}
	cout << answer;
}