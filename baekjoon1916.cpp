#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9;
vector<pair<int, int>> v[1001];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
int dist[1001];

int n, m, from, to, fromToCost, start, dest;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> fromToCost;
		v[from].push_back(make_pair(to, fromToCost));
	}
	cin >> start >> dest;

	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}

	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int distance = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			int cost = v[here][i].second + distance;

			if (dist[next] > cost) {
				dist[next] = cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	cout << dist[dest];
}