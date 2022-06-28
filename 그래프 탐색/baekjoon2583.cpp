#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int m, n, k, x, y, x2, y2, dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool arr[101][101];
vector<int> answer;

void checkMap(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			arr[i][j] = true;
		}
	}
}

int BFS(int x, int y) {
	int result = 1;
	queue<pii> q;
	q.push({ x,y });
	arr[x][y] = true;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curX + dir[i][0];
			int ny = curY + dir[i][1];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (!arr[nx][ny]) {
					result++;
					q.push({ nx, ny });
					arr[nx][ny] = true;
				}
			}
		}
	}
	return result;
}

int main() {
	cin >> m >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> x >> y >> x2 >> y2;
		checkMap(y, x, y2, x2);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if(!arr[i][j])
				answer.push_back(BFS(i, j));
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}