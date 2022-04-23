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
			if (pq.top() > s) { // ���� ���� ������ �ð��� ���ۺ��� ���ĸ� ���ǽ� �ʿ�
				answer++;
			}
			else {
				pq.pop(); // �ش� ��� �ð� out
			}
		}
		else {
			answer++;
		}
		pq.push(e);
	}

	cout << answer;
}