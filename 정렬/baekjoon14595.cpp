#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, from, to, answer;
vector<pii> v;

bool compare(pii& a, pii& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> from >> to;
		v.push_back({ from, to });
	}

	sort(v.begin(), v.end(), compare);

	if (m == 0) {
		cout << n;
		return 0;
	}
	int f = v[0].first;
	int t = v[0].second;
	int answer = n;

	for (int i = 1; i < v.size(); i++) {
		int nf = v[i].first;
		int nt = v[i].second;

		if (nf <= t) { // ���� 1~5�ε� 2~6  �Ǵ� 5~6 ������ ��� ������ 1~6���� ���ش�.
			t = max(t, nt);
		}
		else { // nf > t�� �������� ������ 1~5�ε� 6~8�� ����
			answer -= (t - f);
			f = nf;
			t = nt;
		}
	}

	answer -= (t - f);

	cout << answer;
}