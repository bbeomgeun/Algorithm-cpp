#include <iostream>
using namespace std;

int dp[1001], N;

int main() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 3;
	
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	cout << dp[N];
}