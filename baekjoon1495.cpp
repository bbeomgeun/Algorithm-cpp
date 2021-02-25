#include <iostream>
using namespace std;

int n, s, m, v[101], dp[101][1001];

int main() {
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = -1;
		}
	}

	dp[0][s] = 0; // 시간복잡도는 O(N*M)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j] == i) {
				if (j + v[i] <= m) {
					dp[i + 1][j + v[i]] = i + 1;
				}
				if (j - v[i] >= 0) {
					dp[i + 1][j - v[i]] = i + 1;
				}
			}
		}
	}

	int mx = -1;
	for (int i = 0; i <= m; i++) {// 마지막 곡 순서에 켤 수 있는 볼륨들 중 최대(인덱스)
		if (dp[n][i] != -1) {
			mx = i;
		}
	}
	cout << mx;
}