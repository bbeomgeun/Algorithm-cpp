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
		// 방금 한 계단 올라온 경우, 무조건 2계단
		// dp[i][1]은 i번째에 i-1에서 한칸 올라온 것 -> dp[i-1][1]을 사용하면 그 전에도 i-2에서 한칸사용해서 올라온것 -> 연속 3칸 사용.
		dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
		//방금 두 계단 올라온 경우, 1계단 or 2계단 모두 가능 (두칸 전에서 한번이던 두번이던 사용가능)
	}

	cout << max(dp[n][1], dp[n][2]);
}