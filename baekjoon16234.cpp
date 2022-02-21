#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, l, r, arr[51][51], answer, check[51][51], moving[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool isBetween(int x, int y, int nx, int ny) {
	return abs(arr[x][y] - arr[nx][ny]) >= l && abs(arr[x][y] - arr[nx][ny]) <= r;
}

vector<pii> BFS(int startX, int startY) {
	queue<pii> q;
	vector<pii> record;
	check[startX][startY] = true;
	q.push({ startX, startY });
	record.push_back({ startX, startY });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + moving[i][0];
			int ny = y + moving[i][1];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!check[nx][ny] && isBetween(x, y, nx, ny)) {
					check[nx][ny] = true;
					q.push({ nx, ny });
					record.push_back({ nx, ny });
				}
			}
		}
	}
	return record;
}

void clearCheck() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}

void movingPerson(vector<vector<pii>>& v) {
	for (auto k : v) {
		int sum = 0;
		for (auto i : k) {
			sum += arr[i.first][i.second];
		}
		int div = sum / k.size();
		for (auto i : k) {
			arr[i.first][i.second] = div;
		}
	}
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		int flag = false;
		vector<vector<pii>> v;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					vector<pii> temp = BFS(i, j);
					if (temp.size() > 1) {
						flag = true;
						v.push_back(temp);
					}
				}
			}
		}
		if (!flag) {
			break;
		}
		answer++;
		clearCheck();
		movingPerson(v);
	}
	cout << answer;
}