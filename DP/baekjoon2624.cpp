#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int t, k, p, n, dp[10001][101];
vector<pii> v;

int main() {
	cin >> t >> k;
	for (int i = 0; i < k; i++) {
		cin >> p >> n;
		v.push_back({ p, n });
	}

	for (int i =1; i <= k; i++) {
		int value = v[i-1].first;
		int cnt = v[i-1].second;
		dp[0][i - 1] = 1;

		for (int j = 1; j <= cnt; j++) {
			for (int m = value * j; m <= t; m++) {
				dp[m][i] += dp[m - (value * j)][i - 1];
			}
		}

		for (int j = 1; j <= t; j++) {
			dp[j][i] += dp[j][i - 1];
		}
	}
	cout << dp[t][k];
}