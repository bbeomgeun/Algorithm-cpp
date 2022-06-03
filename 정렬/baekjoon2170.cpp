#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, from, to, answer, l, r;
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

	l = v.front().first;
	r = v.front().second;

	for (int i = 1; i < v.size(); i++) {
		int curL = v[i].first;
		int curR = v[i].second;

		if (curL <= r) { // °ãÄ¡´Â °æ¿ì
			r = max(r, curR);
		}
		else {
			answer += (r - l);
			l = curL;
			r = curR;
		}
	}
	answer += (r - l);
	cout << answer;
}