#include <iostream>

using namespace std;

int T, N, arr[1001], dp[1001][1001]; // i~j 구간 최대 점수

int calc(int l, int r) {
	if (r - l < 0)	return 0;
	if (dp[l][r]) return dp[l][r];
	if (r - l <= 1) {
		dp[l][r] = max(arr[l], arr[r]);
		return dp[l][r];
	}
	dp[l][r] = arr[l] + min(calc(l + 2,r), calc(l + 1,r - 1)); // 왼쪽 선택 후 친구가 왼,오 최소 선택
	// arr[l] : 내가 왼쪽 선택 / calc(l+2,r) = 친구도 왼쪽 선택한 경우(2개 전진), calc(l+1, r-1) 친구는 오른쪽
	dp[l][r] = max(dp[l][r], arr[r] + min(calc(l,r - 2), calc(l + 1,r - 1))); // 오른쪽 선택 + 친구가 왼,오 최소 선택
	return dp[l][r];
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		cout << calc(0, N - 1) << "\n";
		for (int i = 0; i < N; i++) {
			arr[i] = 0;
			for (int j = 0; j < N; j++) {
				dp[i][j] = 0;
			}
		}
	}
}