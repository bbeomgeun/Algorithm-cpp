#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, arr[51][51], check[51][51], mx, temp, xmove[4] = { 1, -1, 0, 0 }, ymove[4] = { 0, 0, 1, -1 };
int record[51][51];
string s;
vector<pair<int, int>> v;

void BFS(int startx, int starty) {
	queue<pair<int, int>> q;
	check[startx][starty] = true;
	q.push(make_pair(startx, starty));
	temp = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + xmove[i];
			int ny = y + ymove[i];

			if (arr[nx][ny] == 1 && !check[nx][ny]) {
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					record[nx][ny] = record[x][y] + 1;
					temp = max(temp, record[nx][ny]);
				}
			}
		}
	}


}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'L') {
				arr[i][j] = 1;
				v.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		BFS(v[i].first, v[i].second);
		mx = max(temp, mx);
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < m; j++) {
				check[k][j] = false;
				record[k][j] = 0;
			}
		}
	}

	cout << mx;

}