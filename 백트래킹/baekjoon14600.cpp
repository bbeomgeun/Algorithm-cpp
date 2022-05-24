#include <iostream>
#include <cmath>

using namespace std;

int moving[8][3][2] = {
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}},
	{{0,0},{-1,0},{-1,1}},
	{{0,0},{-1,0},{-1,-1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{0,1},{-1,1}},
	{{0,0},{0,-1},{1,-1}},
	{{0,0},{0,-1},{-1,-1}},
};

int n, x, y, arr[5][5];
bool answer = false;

void printArray() {
	for (int i = n; i >=  1; i--) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

bool isOk(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n && arr[x][y] == 0;
}

void DFS(int num, int target) {
	if (target == 0) {
		printArray();
		answer = true;
		return;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0) {
				for (int k = 0; k < 8; k++) {
					int flag = true;
					for (int z = 0; z < 3; z++) {
						int nx = i + moving[k][z][0];
						int ny = j + moving[k][z][1];
						if (!isOk(nx, ny)) {
							flag = false;
							break;
						}
					}
					if (flag) { // 모든 블럭 ok
						for (int z = 0; z < 3; z++) {
							int nx = i + moving[k][z][0];
							int ny = j + moving[k][z][1];
							arr[nx][ny] = num;
						}
						DFS(num + 1, target - 3);
						if (answer)
							return;
						for (int z = 0; z < 3; z++) {
							int nx = i + moving[k][z][0];
							int ny = j + moving[k][z][1];
							arr[nx][ny] = 0;
						}
					}
				}
				if (answer)
					return;
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> y >> x;
	arr[x][y] = -1;

	n = pow(2, n);

	DFS(1, n*n - 1);
	
}