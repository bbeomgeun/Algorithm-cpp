#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int V, E, start, target, from, to, weight, dis[501];
vector<pii> v[501], v1[501], toDelete;
bool check[501][501], bfsCheck[501];

void dijkstra(int startX, int target) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dis[startX] = 0;
	pq.push(make_pair(0, startX));

	while (!pq.empty()) {
		int now_distance = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (x == target) {
			return;
		}

		for (auto k : v[x]) {
			int next = k.first;
			int weight = k.second;

			if (dis[next] > now_distance + weight && !check[x][next]) {
				dis[next] = now_distance + weight;
				pq.push(make_pair(dis[next], next));
			}
		}
	}
}

void BFS(int startX) {
	queue<int> q;
	
	q.push(startX);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (bfsCheck[x])
			continue;
		bfsCheck[x] = true;

		for (auto k : v1[x]) {
			int next = k.first;
			int weight = k.second;

			if (dis[next] == dis[x] - weight) { // 역으로 도착지점의 최단경로값에서 간선 가중치 뺀 것이 그 점의 최단경로값 == 최단경로이다.
				toDelete.push_back(make_pair(next, x));
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> V >> E;
		if (V == 0 && E == 0)
			return 0;

		for (int i = 0; i < V; i++) {
			v[i].clear();
			v1[i].clear();
		}
		
		toDelete.clear();
		for (int i = 0; i <= V; i++) {
			dis[i] = INF;
			for (int j = 0; j <= V; j++) {
				check[i][j] = false;
			}
		}

		cin >> start >> target;
		for (int i = 0; i < E; i++) {
			cin >> from >> to >> weight;
			v[from].push_back(make_pair(to, weight));
			v1[to].push_back(make_pair(from, weight));
		}

		dijkstra(start, target);

		if (dis[target] == INF) {
			cout << -1 << "\n";
			continue;
		}

		BFS(target);

		for (int i = 0; i <= V; i++) {
			dis[i] = INF;
			bfsCheck[i] = false;
		}

		for (auto k : toDelete) { // 최단경로 없애기
			int from = k.first;
			int to = k.second;
			check[from][to] = true;
		}

		dijkstra(start, target);

		if (dis[target] == INF) {
			cout << -1 << "\n";
		}
		else
			cout << dis[target] << "\n";
	}
}