#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, M, from, to, dp[101][101];
vector<int> v[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		dp[from][to] = 1;
		dp[to][from] = 1;
	}

	int answer = INF;
	int num1 = 0;
	int num2 = 0;
	for (int k = 1; k <= N; k++) {
		for (int i =1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					dp[i][j] = 0;
				else
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			int tempAnswer = 0;
			for (int num = 1; num <= N; num++) {
				tempAnswer += min(dp[i][num], dp[j][num]);
			}
			if (tempAnswer < answer) {
				answer = tempAnswer;
				num1 = i;
				num2 = j;
			}
		}
	}
	cout << num1 << " " << num2 << " " << answer*2;

}