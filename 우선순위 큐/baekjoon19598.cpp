#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, from, to;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pii> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		v.push_back({ from, to });
	}

	sort(v.begin(), v.end());

	pq.push({v.front().second }); // 끝나는 시간
	int answer = 1;

	for (int i = 1; i < v.size(); i++) {
		int f = v[i].first;
		int to = v[i].second;

		if (pq.top() > f) { // 현재 진행 중인 회의가 시작시간보다 늦게 끝나면
			answer++;
		}
		else { // 끝나는 시간이 동일하거나 이미 끝났다면
			pq.pop();
		}
		pq.push(to);
	}
	cout << answer;
}