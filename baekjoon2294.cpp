#include <iostream>
#define INF 987654321
using namespace std;

int n, k, coin[101], dp[10001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = 0; i <= k; i++) {
		dp[i] = INF;
	}

	dp[0] = 0;

	for (int i = 0; i <n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]]+1);
		}
	}

	if (dp[k] == INF) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}
}