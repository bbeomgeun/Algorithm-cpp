#include <iostream>

using namespace std;

int N, arr[100001][3], dp[3];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		dp[i] = arr[0][i];
	}

	for (int i = 1; i < N; i++) {
		int first = max(dp[0], dp[1]) + arr[i][0];
		int mid = max(max(dp[0], dp[1]), dp[2]) + arr[i][1];
		int last = max(dp[1], dp[2]) + arr[i][2];
		dp[0] = first;
		dp[1] = mid;
		dp[2] = last;
	}

	int maxDp = max(max(dp[0], dp[1]), dp[2]);

	for (int i = 0; i < 3; i++) {
		dp[i] = arr[0][i];
	}

	for (int i = 1; i < N; i++) {
		int first = min(dp[0], dp[1]) + arr[i][0];
		int mid = min(min(dp[0], dp[1]), dp[2]) + arr[i][1];
		int last = min(dp[1], dp[2]) + arr[i][2];
		dp[0] = first;
		dp[1] = mid;
		dp[2] = last;
	}

	int minDp = min(min(dp[0], dp[1]), dp[2]);

	cout << maxDp << " " << minDp;
}