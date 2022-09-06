#include <iostream>
#include <vector>

using namespace std;

int n, m;
string input, answer;

bool isCorrect(char from, char to){
	if (from == 'i') {
		if (to == 'i' || to == 'j' || to == 'l')
			return true;
		else
			return false;
	}
	else if (from == 'v') {
		if (to == 'w' || to == 'v')
			return true;
		else
			return false;
	}
	else if (from == to)
		return true;
	else
		return false;
}


int main() {
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	cin >> input >> answer;

	for (int i = 0; i <= n; i++) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= m; j++) {
		dp[0][j] = j;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isCorrect(input[i], answer[j])) {
				dp[i+1][j+1] = dp[i][j];
			}
			else {
				dp[i + 1][j + 1] = min(min(dp[i][j], dp[i][j+1]), dp[i+1][j]) + 1;
			}
		}
	}

	cout << dp[n][m];
}
