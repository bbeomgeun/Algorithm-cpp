#include <iostream>
#include <algorithm>
using namespace std;

int stairs[301], n;
int dp[301][2];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
	}
	dp[1][1] = dp[1][2] = stairs[1];
	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][2] + stairs[i];
		// ��� �� ��� �ö�� ���, ������ 2���
		// dp[i][1]�� i��°�� i-1���� ��ĭ �ö�� �� -> dp[i-1][1]�� ����ϸ� �� ������ i-2���� ��ĭ����ؼ� �ö�°� -> ���� 3ĭ ���.
		dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
		//��� �� ��� �ö�� ���, 1��� or 2��� ��� ���� (��ĭ ������ �ѹ��̴� �ι��̴� ��밡��)
	}

	cout << max(dp[n][1], dp[n][2]);
}