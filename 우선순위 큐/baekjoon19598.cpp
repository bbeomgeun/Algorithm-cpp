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

	pq.push({v.front().second }); // ������ �ð�
	int answer = 1;

	for (int i = 1; i < v.size(); i++) {
		int f = v[i].first;
		int to = v[i].second;

		if (pq.top() > f) { // ���� ���� ���� ȸ�ǰ� ���۽ð����� �ʰ� ������
			answer++;
		}
		else { // ������ �ð��� �����ϰų� �̹� �����ٸ�
			pq.pop();
		}
		pq.push(to);
	}
	cout << answer;
}