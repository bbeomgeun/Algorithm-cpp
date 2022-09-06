#include <iostream>
#include <vector>

using namespace std;

string fir, sec;
int n1, n2;

int main() {
	cin >> fir >> sec;
	n1 = fir.size();
	n2 = sec.size();
	
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
	
	for (int i = 0; i <= n1; i++) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= n2; i++) {
		dp[0][i] = i;
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (fir[i] == sec[j]) {
				dp[i + 1][j + 1] = dp[i][j];
			}
			else {
				dp[i + 1][j + 1] = min(min(dp[i][j], dp[i][j + 1]), dp[i + 1][j]) + 1;
			}
		}
	}

	cout << dp[n1][n2];
}