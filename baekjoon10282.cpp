#include <iostream>
#include <queue>
#define INF 987654231

using namespace std;
typedef pair<int, int> pii;
int T, N, D, C, a, b, s, dis[10001];
vector<pii> v[10001];

void dijkstra(int startX) {
	priority_queue<pii, vector<pii>, greater<pii>> pq; // minHeap
	pq.push({ 0, startX });
	dis[startX] = 0;

	while (!pq.empty()) {
		int distanceX = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int weight = v[x][i].second;
			int nx = v[x][i].first;

			if (dis[nx] > distanceX + weight) {
				dis[nx] = distanceX + weight;
				pq.push({ dis[nx], nx });
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> D >> C;
		for (int i = 0; i <= N; i++) {
			dis[i] = INF;
			v[i].clear();
		}

		for (int d = 0; d < D; d++) {
			cin >> a >> b >> s;
			v[b].push_back({ a, s });
		}
		dijkstra(C);
		int answer = 0; int value = 0;
		for (int i = 1; i <= N; i++) {
			if (dis[i] != INF) {
				answer++;
				value = max(value, dis[i]);
			}
		}
		cout << answer << " " << value << "\n";
	}
}