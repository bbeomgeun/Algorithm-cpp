#include <iostream>
#include <queue>
using namespace std;

int bound[101][101], N, height, resultMax, xmove[4] = { 1, -1, 0, 0 }, ymove[4] = { 0, 0, 1, -1 };
bool check[101][101];

void BFS(int i, int j, int key) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tempX = x + xmove[i];
			int tempY = y + ymove[i];
			if (bound[tempX][tempY] <= key && !check[tempX][tempY] && tempX < N && tempY < N && tempX >= 0 && tempY >= 0) {
				q.push(make_pair(tempX, tempY));
				check[tempX][tempY] = true;
			}
		}
	}
}

void BFS2(int i, int j, int key) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tempX = x + xmove[i];
			int tempY = y + ymove[i];
			if (bound[tempX][tempY] > key && !check[tempX][tempY] && tempX < N && tempY < N && tempX >= 0 && tempY >= 0) {
				q.push(make_pair(tempX, tempY));
				check[tempX][tempY] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bound [i][j];
			if (height < bound[i][j])
				height = bound[i][j]; // 높이정보범위용
		}
	}
	if (height >= 100)
		height = 100;

	for (int k = 0; k <= height; k++) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				check[i][j] = false;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bound[i][j] <= k && !check[i][j]) {
					BFS(i, j, k);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (bound[i][j] > k && !check[i][j]) {
					count += 1;
					BFS2(i, j, k);
				}
			}
		}
		if (resultMax < count)
			resultMax = count;
	}
	if (resultMax == 0)
		cout << 1;
	else
		cout << resultMax;
}