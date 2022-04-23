#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, from, to, answer;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		v.push_back({ from, to });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int s = v[i].first;
		int e = v[i].second;

		if (!pq.empty()) {
			if (pq.top() > s) { // 제일 빨리 끝나는 시간이 시작보다 이후면 강의실 필요
				answer++;
			}
			else {
				pq.pop(); // 해당 사용 시간 out
			}
		}
		else {
			answer++;
		}
		pq.push(e);
	}

	cout << answer;
}