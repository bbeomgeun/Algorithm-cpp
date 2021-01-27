#include <iostream>
#include <algorithm>
using namespace std;

int dp[31], N;

int main() {
	cin >> N;
	if (N % 2) {
		cout << 0;
		return 0;
	}

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}
	cout << dp[N];
}