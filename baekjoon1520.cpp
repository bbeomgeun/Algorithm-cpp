#include <iostream>

using namespace std;

int M, N, arr[501][501], xmove[4] = { 1, -1, 0,0 }, ymove[4] = { 0,0,1,-1 }, dp[501][501];

int DFS(int x, int y) {
	
	if (dp[x][y] != -1 ) {
		return dp[x][y];
	}

	if (x == M - 1 && y == N - 1) {
		return 1;
	}

	dp[x][y] = 0; // 방문체크

	for (int i = 0; i < 4; i++) {
		int tempx = x + xmove[i];
		int tempy = y + ymove[i];

		if (tempx >= 0 && tempx < M && tempy >= 0 && tempy < N) {
			if ( arr[tempx][tempy] < arr[x][y]) {
				dp[x][y] += DFS(tempx, tempy);
			}
		}
	}
	// 현재 좌표에서 갈 수 있는 곳이 없으면 현재 좌표까지 갈 수 있는 경우의 수를 반환
	//return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}

	cout<<DFS(0, 0);
	
}