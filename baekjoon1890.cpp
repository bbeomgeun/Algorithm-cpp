#include <iostream>

using namespace std;

int N, arr[101][101], xmove[2] = { 1, 0 }, ymove[2] = { 0,1 };
long long dp[101][101];

long long DFS(int x, int y) {

	if (x == N - 1 && y == N - 1) {
		return 1;
	}

	if (dp[x][y] == -1) {
		dp[x][y] = 0;

		for (int i = 0; i < 2; i++) {
			int tx = x + arr[x][y] * xmove[i];
			int ty = y + arr[x][y] * ymove[i];

			if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
				dp[x][y] += DFS(tx, ty);
			}
		}
	}
	return dp[x][y];
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	cout<<DFS(0, 0);
}