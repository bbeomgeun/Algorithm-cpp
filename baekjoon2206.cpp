#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, arr[1001][1001], check[1001][1001][2], dp[1001][1001][2];
int xmove[4] = { 1, -1, 0,0 }, ymove[4] = { 0,0,1,-1 };
int result;
queue<pair<int, pair<int, int>>> q;
string s;

int BFS(int x, int y, int b) {
	check[x][y][b] = true;
	q.push(make_pair(b, make_pair(x, y)));
	dp[x][y][b] = 1;

	while (!q.empty()) {
		int tx = q.front().second.first;
		int ty = q.front().second.second;
		int block = q.front().first;
		q.pop();

		if (tx == N - 1 && ty == M - 1) {
			return dp[tx][ty][block];
		}

		for (int i = 0; i < 4; i++) {
			int nx = tx + xmove[i];
			int ny = ty + ymove[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if ( block && arr[nx][ny] == 1) {
					dp[nx][ny][block-1] = dp[tx][ty][block] + 1;
					check[nx][ny][block-1] = true;
					q.push(make_pair(block-1, make_pair(nx, ny)));
				}
				else if(!check[nx][ny][block] && arr[nx][ny] == 0){
					dp[nx][ny][block] = dp[tx][ty][block] + 1;
					check[nx][ny][block] = true;
					q.push(make_pair(block, make_pair(nx, ny)));
				}
			}
		}

	}
	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j]-'0';
		}
	}
		
	cout << BFS(0, 0, 1);
}