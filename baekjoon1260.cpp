#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> a[1001];
bool check_dfs[1001];
bool check_bfs[1001];
int N, M, start, u, v;

void dfs(int node) {
	check_dfs[node] = true;
	cout << node << " ";

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];

		if (check_dfs[next] == false)
			dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check_bfs[start] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		cout << node << " ";

		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];

			if (check_bfs[next] == false) {
				q.push(next);
				check_bfs[next] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M >> start;

	for (int i = 0; i < M; i++) { // 간선 갯수만큼
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) // 노드 갯수만큼 정렬
		sort(a[i].begin(), a[i].end());

	dfs(start);
	cout << "\n";
	bfs(start);

	return 0;
}