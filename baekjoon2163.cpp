#include <iostream>
using namespace std;

int dp[301], n, m;

int main() {
	cin >> n >> m;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= 300; i++) {
		dp[i] = i - 1;
	}

	int max = n>=m ? n : m;
	int min = n < m ? n : m;

	cout << dp[max] + (min - 1) * max;
}