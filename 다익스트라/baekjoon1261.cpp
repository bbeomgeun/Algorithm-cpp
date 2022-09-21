#include<iostream>
#include <algorithm>
#include <queue>

#define INF 10001

using namespace std;

int n, m, dp[101][101], field[101][101], moveX[4] = { 0, 0, 1, -1 }, moveY[4] = { 1, -1, 0, 0 };
int cnt;
int result = INF;
string s;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

void BFS(int startX, int startY) {
	pq.push(make_pair(0, make_pair(startX, startY)));
	dp[startX][startY] = 0;


	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int dist = pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = x + moveX[i];
			int nextY = y + moveY[i];

			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
				if (dp[nextX][nextY] > dist + field[nextX][nextY]) {
					dp[nextX][nextY] = dist + field[nextX][nextY];
					pq.push(make_pair(dp[nextX][nextY], make_pair(nextX, nextY)));
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			field[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = INF;
		}
	}
	BFS(0, 0);

	cout << dp[n - 1][m - 1];

}