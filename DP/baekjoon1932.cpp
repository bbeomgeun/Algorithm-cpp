#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501], n, dp[501][501], mx;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0] + dp[0][0];
	dp[1][1] = arr[1][1] + dp[0][0];

	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 ) {
				dp[i][j] = arr[i][j] + dp[i - 1][j];
				mx = max(mx, dp[i][j]);
			}
			else if (j == i) {
				dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
				mx = max(mx, dp[i][j]);
			}
			else {
				dp[i][j] = arr[i][j] + max(dp[i - 1][j-1], dp[i - 1][j]);
				mx = max(mx, dp[i][j]);
			}
		}
	}
	cout << mx;
}