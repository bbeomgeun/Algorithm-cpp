#include <iostream>

using namespace std;

int T, N, arr[1001], dp[1001][1001]; // i~j ���� �ִ� ����

int calc(int l, int r) {
	if (r - l < 0)	return 0;
	if (dp[l][r]) return dp[l][r];
	if (r - l <= 1) {
		dp[l][r] = max(arr[l], arr[r]);
		return dp[l][r];
	}
	dp[l][r] = arr[l] + min(calc(l + 2,r), calc(l + 1,r - 1)); // ���� ���� �� ģ���� ��,�� �ּ� ����
	// arr[l] : ���� ���� ���� / calc(l+2,r) = ģ���� ���� ������ ���(2�� ����), calc(l+1, r-1) ģ���� ������
	dp[l][r] = max(dp[l][r], arr[r] + min(calc(l,r - 2), calc(l + 1,r - 1))); // ������ ���� + ģ���� ��,�� �ּ� ����
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