#include <iostream>
#include <cmath>

using namespace std;

int n, m, r, dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int arr[301][301];

void rotation(int c, int len) {
	int rep = r % len;
	for (int i = 0; i < rep; i++) {
		int curLen = len;
		int x = c;
		int y = c;
		int limitX = n - c;
		int limitY = m - c;
		int curDir = 0;
		int curValue = arr[x][y];
		int nValue = 0;
		while (curLen) {
			int nx = x + dir[curDir][0];
			int ny = y + dir[curDir][1];

			if (nx >= c && nx < limitX && ny >= c && ny < limitY) {
				int nValue = arr[nx][ny];
				arr[nx][ny] = curValue;
				curValue = nValue;
				curLen--;
				x = nx;
				y = ny;
			}
			else {
				curDir = (curDir + 1) % 4;
			}
		}
	}
}

void printArr() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// r번 전체 회전하지말고 각 껍질을 r % len 만큼 회전
	int cnt = min(n, m) / 2;
	int tempN = n;
	int tempM = m;

	for (int i = 0; i < cnt; i++) {
		int len = tempN * 2 + tempM * 2 - 4;
		rotation(i, len);
		tempN -=2;
		tempM -=2;
	}

	printArr();
}
