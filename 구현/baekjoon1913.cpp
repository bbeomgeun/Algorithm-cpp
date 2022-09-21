#include <iostream>

using namespace std;

int arr[1001][1001];
int n, target, ansX, ansY;

bool finish(int x, int y) {
	return x == 0 && y == 0;
}

void makeSquare(int n) {
	int x = (n - 1) / 2;
	int y = (n - 1) / 2;
	int num = 1;
	int temp = 1;
	arr[x][y] = num++; // 1

	while (1) {

		for (int i = 0; i < temp; i++) {
			arr[--x][y] = num++;
			if (finish(x, y))
				return;
		}

		for (int i = 0; i < temp; i++) {
			arr[x][++y] = num++;
			if (finish(x, y))
				return;
		}
		temp++;

		for (int i = 0; i < temp; i++) {
			arr[++x][y] = num++;
			if (finish(x, y))
				return;
		}

		for (int i = 0; i < temp; i++) {
			arr[x][--y] = num++;
			if (finish(x, y))
				return;
		}
		temp++;
	}
}

int main() {
	cin >> n >> target;

	makeSquare(n);
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == target) {
				ansX = i;
				ansY = j;
			}
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << ansX+1 << " " << ansY+1;
}