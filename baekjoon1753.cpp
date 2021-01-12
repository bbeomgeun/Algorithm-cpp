#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int V, E, start, u, v, w;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
vector<pair<int, int>> vec[20001];
int dist[20001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E >> start;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		vec[u].push_back(make_pair(v,w)); 
	}
	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}

	pq.push(make_pair(0, start)); // cost 순 정렬
	dist[start] = 0;

	while (!pq.empty()) {
		int distance = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[here].size(); i++) {
			int tempNext = vec[here][i].first; // 방문할 node
			int nextCost = vec[here][i].second; // from~to의 가중치

			if (dist[tempNext] > nextCost + distance) { // 방문할 노드의 값이 현재 노드 + 간선가중치보다 크면 갱신
				dist[tempNext] = nextCost + distance;
				pq.push(make_pair(dist[tempNext], tempNext)); // 방문할 노드의 노드 번호와 노드의 값을 pq에 넣어준다.
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF" << "\n"; 
		else
			cout << dist[i] << "\n";
	}

}