#include <iostream>
#include <cmath>
using namespace std;
#define num 1000000000

long long dp[101][11], n;

int main() {
	cin >> n;
	for(int i = 1 ; i <= 9; i++)
		dp[1][i] = 1;
	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if(j-1 < 0)
				dp[i][j] = (dp[i - 1][j + 1]) % num;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % num;
		}
	}

	long long sum = 0;

	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}

	cout << sum % num;
}