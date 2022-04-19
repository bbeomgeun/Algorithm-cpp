#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, from, to, answer;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> endPoint;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> from >> to;
		v.push_back({ from, to });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int s = v[i].first;
		int e = v[i].second;

		if (!endPoint.empty()) {
			if (endPoint.top() > s) { // 겹침
				answer++;
			}
			else { // 지금 있는 선분과 안 겹침
				endPoint.pop();
			}
		}
		else {
			answer++;
		}
		endPoint.push(e);

	}
	cout << answer;
}