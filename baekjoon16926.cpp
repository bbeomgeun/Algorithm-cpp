#include <iostream>
#include <cmath>

using namespace std;

int n, m, r;
int arr[301][301];

void rotation(int x, int y) {

	int count = min(x, y) / 2;

	for (int c = 0; c < count; c++) {
		int xMax = x - c - 1;
		int yMax = y - c - 1;

		int start = arr[c][c];

		for (int j = c; j < yMax; j++) { // 0 ~ x-1±îÁö
			arr[c][j] = arr[c][j + 1]; // 0, j <- 0, j+1
		}
		for (int i = c; i < xMax; i++) { // 
			arr[i][yMax] = arr[i+1][yMax]; // 
		}
		for (int j = yMax; j > c; j--) {
			arr[xMax][j] = arr[xMax][j-1];
		}
		for (int i = xMax; i > c; i--) {
			arr[i][c] = arr[i-1][c];
		}
		arr[c + 1][c] = start;
	}
}

int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		rotation(n, m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
	