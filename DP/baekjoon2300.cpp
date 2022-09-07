#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

typedef pair<int, int> pii;

int n, x, y, dp[10001];
vector<pii> v;

int main() {
	cin >> n;
	v.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin()+1, v.end());

	for (int i = 1; i <= n; i++) {
		dp[i] = MAX;
	}

	for (int i = 1; i <= n; i++) {
		int height = 0;
		for (int j = i; j >= 1; j--) {
			height = max(height,  abs(v[j].second));

			dp[i] = min(dp[i], dp[j - 1] + max(height * 2, v[i].first - v[j].first));
		}
	}

	cout << dp[n];
}