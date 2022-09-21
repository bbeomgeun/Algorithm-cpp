#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, room, from, to, limit, answer = 1;

typedef pair<int, int> pii;

vector<pii> v;
priority_queue<int, vector<int>, greater<int>> lastTime;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> room >> from >> to;
		v.push_back({ from, to });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int startTime = v[i].first;
		int endTime = v[i].second;

		if (lastTime.empty()) {
			lastTime.push(endTime);
		}
		else {
			if (lastTime.top() > startTime) { // 아직 안끝난 경우 회의실이 없다.
				answer++;
			}
			else { // 빈 회의실로 들어가면 된다.
					lastTime.pop();
			}
			lastTime.push(endTime);
		}
	}
	cout << answer;
}