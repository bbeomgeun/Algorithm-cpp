#include <iostream>

using namespace std;

int n, arr[501][501], dp[501][501];
int xmove[4] = { 1, -1, 0, 0 }, ymove[4] = { 0,0,1,-1 };

int DFS(int startx, int starty) {
	if (dp[startx][starty] != -1)
		return dp[startx][starty]+1;

	else {
		dp[startx][starty] = 1;

		for (int i = 0; i < 4; i++) {
			int x = startx + xmove[i];
			int y = starty + ymove[i];
			if (x >= 0 && x < n && y >= 0 && y < n) {
				if (arr[x][y] > arr[startx][starty]) {
					dp[startx][starty] = max(dp[startx][starty], DFS(x, y));
				}
			}
		}
		return dp[startx][starty]+1;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				DFS(i, j);
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mx = max(mx, dp[i][j]);
		}
	}
	cout << mx;
}