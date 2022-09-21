#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int n, e, dist[801][3], from, to, dis, mustfrom, mustto;
vector<pair<int, int>> v[801];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>> pq;

void BFS(int start, int idx) {
	pq.push(make_pair(start, 0));
	dist[start][idx] = 0;

	while (!pq.empty()) {
		int now = pq.top().first;
		int now_dist = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int next_dist = v[now][i].second;

			if (dist[next][idx] > dist[now][idx] + next_dist) {
				dist[next][idx] = dist[now][idx] + next_dist;
				pq.push(make_pair(next, dist[next][idx]));
			}
		}
	}
}


int main() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> from >> to >> dis;
		v[from].push_back(make_pair(to, dis));
		v[to].push_back(make_pair(from, dis));
	}
	cin >> mustfrom >> mustto;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			dist[i][j] = INF;
		}
	}

	BFS(1, 0);

	BFS(mustfrom, 1);

	BFS(mustto, 2);

	int ans1 = 0;
	int ans2 = 0;

	if (dist[mustfrom][0] == INF || dist[mustto][1] == INF || dist[n][2] == INF)
		ans1 = -1;
	else
		ans1 = dist[mustfrom][0] + dist[mustto][1] + dist[n][2]; // 1 -> 2 -> 3-> 4

	if (dist[mustfrom][1] == INF || dist[mustto][0] == INF || dist[n][2] == INF)
		ans2 = -1;
	else
		ans2 = dist[mustto][0] + dist[mustfrom][2] + dist[n][1]; //1->3->2->4

	if (ans1 != -1 && ans2 != -1)
		cout << min(ans1, ans2);
	else if (ans1 == -1 && ans2 != -1)
		cout << ans2;
	else if (ans1 != -1 && ans2 == -1)
		cout << ans1;
	else
		cout << -1;

	
}