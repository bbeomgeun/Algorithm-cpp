#include <iostream>

using namespace std;

int T, N, M,coin[21], dp[10001];

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> coin[n];
		}
		dp[0] = 1;
		cin >> M;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[M]<<"\n";
		for (int i = 0; i <= M; i++) {
			dp[i] = 0;
		}
	}
}