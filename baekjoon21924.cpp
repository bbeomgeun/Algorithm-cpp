#include <iostream>
#include <queue>

using namespace std;

int N, M, from, to, weight;
long long total;
int parent[100001];
long long record[100001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>> > pq;

int getParent(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b, int weight) {
	a = getParent(a);
	b = getParent(b);

	if (a == b) {
		return false;
	}

	if (a > b) {
		parent[a] = b;
		record[b] += (record[a] + weight);
	}
	else {
		parent[b] = a;
		record[a] += (record[b] + weight);
	}
	return true;
}

bool find(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	return a == b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	for (int n = 1; n <= N; n++) {
		parent[n] = n;
	}
	for (int m = 0; m < M; m++) {
		cin >> from >> to >> weight;
		total += weight;
		pq.push(make_pair(weight, make_pair(from, to)));
	}

	int answer = 0;

	while (!pq.empty()) {
		int w = pq.top().first;
		int vertex1 = pq.top().second.first;
		int vertex2 = pq.top().second.second;
		pq.pop();

		unionParent(vertex1, vertex2, w);
	}

	for (int i = 1; i < N; i++) {
		if (!find(i, i+1)) {
			cout << -1;
			return 0;
		}
	}
	if (total - record[parent[1]] > 0) {
		cout << total - record[parent[1]];
	}
	else
		cout << 0;
}