#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, from, to, dp[101];
vector<pii> v;
vector<int> rv;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		v.push_back({ from, to });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int r = v[i].second;
		rv.push_back(r);
	}

	for (int i = 0; i < rv.size(); i++) {
		int l = 1;
		for (int j = 0; j < i; j++) {
			if (dp[j] >= l && rv[j] < rv[i]) {
				l++;
			}
		}
		dp[i] = l;
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, dp[i]);
	}

	cout << n - mx;
}