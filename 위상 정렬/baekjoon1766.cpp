#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, one, two, cnt[32001], check[32001];
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> N >> M;
	for (int m = 0; m < M; m++) {
		cin >> one >> two;
		v[one].push_back(two);
		cnt[two]++; // indegree °¹¼ö
	}

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int next = pq.top();
		pq.pop();
		cout << next << " ";
		for (int i = 0; i < v[next].size(); i++) {
			int nx = v[next][i];
			cnt[nx]--;
			if (cnt[nx] == 0) {
				pq.push(nx);
			}
		}
	}

}