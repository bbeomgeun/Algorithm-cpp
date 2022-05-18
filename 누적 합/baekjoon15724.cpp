#include <iostream>
#define MAX 1025

using namespace std;

int arr[MAX][MAX], dp[MAX][MAX];
int n, m, num, k, a, b, c, d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c >> d;
		cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] << "\n";
	}
}