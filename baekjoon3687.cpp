#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt[9] = { 0, 0, 1, 7, 4, 2, 0, 8, 10 };
int T, num;
long long dp[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> num;
		int mx = num;
		int minx = num;
		string maax = "";

		for (int i = 2; i < 9; i++) {
			dp[i] = cnt[i];
		}
		dp[6] = 6;

		for (int i = 9; i <= 100; i++) {
			dp[i] = dp[i - 2] * 10 + cnt[2];
			for (int j = 3; j < 8; j++) {
				dp[i] = min(dp[i], dp[i - j] * 10 + cnt[j]);
			}
		}
		cout << dp[num];
		cout << " ";
		if (mx % 2 == 0) {
			while (mx) {
				maax += '1';
				mx -= 2;
			}
		}
		else if (mx > 3) {
			mx -= 3;
			maax += '7';
			while (mx) {
				maax += '1';
				mx -= 2;
			}
		}
		else {
			maax = '7';
		}

		for (int i = 0; i < maax.size(); i++) {
			cout << maax[i];
		}
		cout << "\n";
	}
}