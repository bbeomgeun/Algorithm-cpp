#include <iostream>
#include <algorithm>

using namespace std;

int n, num, dp[1001], arr[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		int ans = 0;
		int minX = arr[i];
		int maxX = arr[i];

		for (int j = i-1; j > 0; j--) {
			minX = min(minX, arr[j]);
			maxX = max(maxX, arr[j]);

			dp[i] = max(dp[i], dp[j - 1] + (maxX - minX));
		}
	}

	cout << dp[n];
}