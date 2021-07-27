#include <iostream>
#include <vector>

using namespace std;

int N, answer, xMove[4] = { 0, 0, -1, 1 }, yMove[4] = { -1, 1, 0, 0 };
vector<vector<int>> arr(21, vector<int>(21, 0));

vector<vector<int>> movingMap(vector<vector<int>> v, int direction) {
	bool check[21][21] = { false, };
	if(direction == 0){ // 왼쪽이동
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v[i][j] == 0)
					continue;
				int x = i;
				int y = j;
				int nx, ny;
				while (1) {
					nx = x + xMove[direction];
					ny = y + yMove[direction];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						break;
					if (v[nx][ny] == 0) {
						v[nx][ny] = v[x][y];
						v[x][y] = 0;
					}
					else {
						if (!check[nx][ny] && (v[nx][ny] == v[x][y])) {
							v[nx][ny] += v[x][y];
							v[x][y] = 0;
							check[nx][ny] = true;
						}
						break;
					}
					x = nx;
					y = ny;
				}
			}
		}
	}

	if (direction == 1) { // 오른쪽이동
		for (int i = 0; i < N; i++) {
			for (int j = N-1; j >= 0; j--) {
				if (v[i][j] == 0)
					continue;
				int x = i;
				int y = j;
				int nx, ny;
				while (1) {
					nx = x + xMove[direction];
					ny = y + yMove[direction];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						break;
					if (v[nx][ny] == 0) {
						v[nx][ny] = v[x][y];
						v[x][y] = 0;
					}
					else {
						if (!check[nx][ny] && (v[nx][ny] == v[x][y])) {
							v[nx][ny] += v[x][y];
							v[x][y] = 0;
							check[nx][ny] = true;
						}
						break;
					}
					x = nx;
					y = ny;
				}
			}
		}
	}

	if (direction == 2) { // 위로 이동
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v[i][j] == 0)
					continue;
				int x = i;
				int y = j;
				int nx, ny;
				while (1) {
					nx = x + xMove[direction];
					ny = y + yMove[direction];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						break;
					if (v[nx][ny] == 0) {
						v[nx][ny] = v[x][y];
						v[x][y] = 0;
					}
					else {
						if (!check[nx][ny] && (v[nx][ny] == v[x][y])) {
							v[nx][ny] += v[x][y];
							v[x][y] = 0;
							check[nx][ny] = true;
						}
						break;
					}
					x = nx;
					y = ny;
				}
			}
		}
	}

	if (direction == 3) { // 아래 이동
		for (int i = N-1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (v[i][j] == 0)
					continue;
				int x = i;
				int y = j;
				int nx, ny;
				while (1) {
					nx = x + xMove[direction];
					ny = y + yMove[direction];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						break;
					if (v[nx][ny] == 0) {
						v[nx][ny] = v[x][y];
						v[x][y] = 0;
					}
					else {
						if (!check[nx][ny] && (v[nx][ny] == v[x][y])) {
							v[nx][ny] += v[x][y];
							v[x][y] = 0;
							check[nx][ny] = true;
						}
						break;
					}
					x = nx;
					y = ny;
				}
			}
		}
	}
	return v;
}

void gameStart(vector<vector<int>> & original, int cur) {
	if (cur == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				answer = max(answer, original[i][j]);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> tempArr(21, vector<int>(21, 0));
		tempArr = movingMap(original, i);
		gameStart(tempArr, cur + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	gameStart(arr, 0);

	cout << answer;
}