#include <iostream>

using namespace std;

int num, arr[1001][3], dp[1001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	int answer = 10000000;
	for (int i = 0; i < 3; i++) {
		dp[0][0] = 9999;
		dp[0][1] = 9999;
		dp[0][2] = 9999;

		dp[0][i] = arr[0][i];

		for (int j = 1; j < num; j++) {
			dp[j][0] = arr[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = arr[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = arr[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		for (int j = 0; j < 3; j++) {
			if (i == j)
				continue;
			else {
				answer = min(answer, dp[num - 1][j]);
			}
		}
	}
	cout << answer;
}