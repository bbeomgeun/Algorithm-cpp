#include <iostream>
#include <queue>

using namespace std;

int map[101][101], N, M;
bool check[101][101];
int dis[101][101];
string input;
int xPos[4] = { 1, -1, 0, 0 };
int yPos[4] = { 0, 0, -1, 1 };

int bfs(int n, int m) {
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));

	while (!q.empty()) {
		for (int i = 0; i < q.size(); i++) {
			int x = q.front().first;
			int y = q.front().second;
		
			if (x == n && y == m) {
				return dis[x][y] + 1;
			}

			q.pop();

			for (int i = 0; i < 4; i++) {
				int tmpX = x+ xPos[i];
				int tmpY = y + yPos[i];

				if ((map[tmpX][tmpY] == 1 && check[tmpX][tmpY] == false && tmpX > 0 && tmpY > 0 && tmpX <= n && tmpY <= m) == true) {
					q.push(make_pair(tmpX, tmpY));
					check[tmpX][tmpY] = true;
					dis[tmpX][tmpY] = dis[x][y] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 1; j <= input.length(); j++) {
			map[i][j] = input[j - 1] - 48;
		}
	}

	cout<< bfs(N, M);




	return 0;
}