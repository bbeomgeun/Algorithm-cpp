#include <iostream>

using namespace std;

int n, arr[501][501], dp[501][501], check[501][501];
int xmove[4] = { 1, -1, 0, 0 }, ymove[4] = { 0,0,1,-1 };

int DFS(int startx, int starty) {
	if (check[startx][starty])
		return 0;
	else {
		check[startx][starty] = true;
		
		for (int i = 0; i < 4; i++) {
			int x = startx + xmove[i];
			int y = starty + ymove[i];
			if (x >= 0 && x < n && y >= 0 && y < n) {
				if (!check[x][y] && arr[x][y] > arr[startx][starty]) {
					dp[startx][starty] += DFS(x, y);
				}
			}
		}
		return 1;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j])
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