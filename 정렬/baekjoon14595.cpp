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

		if (nf <= t) { // 현재 1~5인데 2~6  또는 5~6 들어오는 경우 범위를 1~6으로 해준다.
			t = max(t, nt);
		}
		else { // nf > t는 이제까지 범위가 1~5인데 6~8이 들어옴
			answer -= (t - f);
			f = nf;
			t = nt;
		}
	}

	answer -= (t - f);

	cout << answer;
}