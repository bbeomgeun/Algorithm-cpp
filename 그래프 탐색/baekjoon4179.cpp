#include <iostream>
#include <queue>
#include <vector>
#define MAX 987654321

using namespace std;

typedef pair<int, int> pii;

int r, c, startX, startY, fireX, fireY, moving[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int check[1001][1001], fireMap[1001][1001];
char m[1001][1001];
vector<pii> v;

struct Point {
	int x;
	int y;
	int cnt;
};

int BFS(int startX, int startY) {
	queue<Point> q;
	q.push({ startX, startY, 0 });
	check[startX][startY] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if (x == 0 || y == 0 || x == r -1 || y == c-1) {
			return cnt+1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + moving[i][0];
			int ny = y + moving[i][1];
			int nCnt = cnt + 1;

			if (nx >= 0 && nx < r && ny >= 0 && ny < c && !check[nx][ny] && m[nx][ny] == '.') {
				if (fireMap[nx][ny] > nCnt) {
					check[nx][ny] = true;
					q.push({ nx, ny, nCnt });
				}
			}
		}
	}
	return -1;
}

void fireBFS(int x, int y) {
	queue<pii> q;
	q.push({ x, y });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + moving[i][0];
			int ny = y + moving[i][1];

			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (m[nx][ny] != '#' && fireMap[nx][ny] > fireMap[x][y]+1) {
					fireMap[nx][ny] = fireMap[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
			if (m[i][j] == 'J') {
				startX = i;
				startY = j;
			}
			if (m[i][j] == 'F') {
				v.push_back({ i, j });
				fireMap[i][j] = 0;
			}
			else {
				fireMap[i][j] = MAX;
			}
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		fireBFS(v[i].first, v[i].second);
	}
	int result = BFS(startX, startY);

	if (result == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << result;
	}
}