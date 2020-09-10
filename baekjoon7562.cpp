#include <iostream>
#include <queue>

using namespace std;
int N, I, curX, curY, toX, toY;
int disX[8] = { 2, 2, 1, 1, -2, -2, -1, -1 };
int disY[8] = { 1, -1, 2, -2, 1, -1, 2, -2 };

int bfs(int size, int x, int y, int X, int Y) {
	int chess[301][301] = { 0, };
	bool checked[301][301] = { 0, };
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int startX = q.front().first;
		int startY = q.front().second;
		checked[startX][startY] = true;
		q.pop();

		if (startX == X && startY == Y) {
			return chess[X][Y];
		}

		for (int i = 0; i < 8; i++) {
			int tempX = startX + disX[i];
			int tempY = startY + disY[i];
			if (tempX >= 0 && tempY >= 0 && tempX < size && tempY < size && !checked[tempX][tempY]) {
				q.push(make_pair(tempX, tempY));
				checked[tempX][tempY] = true;
				chess[tempX][tempY] = chess[startX][startY] + 1;

			}
		}
	}
}

int main() {
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> I >> curX >> curY >> toX >> toY;
		*(arr + i) = bfs(I, curX, curY, toX, toY);
	}
	for (int i = 0; i < N; i++) {
		cout << *(arr + i) << "\n";
	}
	return 0;
}