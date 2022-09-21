#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int parent[100001], N, M, from, to, weight;
vector<int> weightList;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
unordered_map<int, bool> m;

int getParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b)
		return false;
	if (a > b)
		parent[a] = b; // 큰 수의 부모가 작은 수
	else
		parent[b] = a;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int answer = 0;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int n = 0; n < M; n++) {
		cin >> from >> to >> weight;
		pq.push(make_pair(weight, make_pair(from, to)));
	}
	while (!pq.empty()) {
		int w = pq.top().first;
		int f = pq.top().second.first;
		int t = pq.top().second.second;
		pq.pop();

		if (unionParent(f, t)) {
			answer += w;
			weightList.push_back(w);
		}
	}

	sort(weightList.begin(), weightList.end());

	cout << answer - weightList.back();
	
}