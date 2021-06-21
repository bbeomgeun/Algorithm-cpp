#include <iostream>

using namespace std;

int N, arr[100001], dp[100001][2];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i][0] = arr[i];
	}
	int answer = dp[0][0];
	dp[0][1] = answer;

	for (int i = 1; i < N; i++) {
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + arr[i]);
		if (arr[i] < 0) { // ������ ���
			dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]); // ������ ���ص� ū ��� vs ���� �� �� �� ū ���
		}
		else { // ����� �׳� ������Ʈ
			dp[i][1] = dp[i - 1][1] + arr[i];
		}
		answer = max(answer, max(dp[i][0], dp[i][1]));
	}
	cout << answer;
}