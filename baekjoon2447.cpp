#include <iostream>

using namespace std;
int n;
char star[6562][6562];

void printStar(int col, int row, int size) {
	int tempsize = size / 3;
	if (size == 3) {
		for (int i = col; i < col + size; i++) {
			for (int j = row; j < row + size; j++) {
				if (i >= col + tempsize && i < col + tempsize * 2 && j >= row + tempsize && j < row + tempsize * 2) {
					star[i][j] = ' ';
				}
				else {
					star[i][j] = '*';
				}
			}
		}
	}

	else {
		for (int i = col; i < col + size; i += tempsize) {
			for (int j = row; j < row + size; j += tempsize) {
				if (i >= col + tempsize && i < col + tempsize * 2 && j >= row + tempsize && j < row + tempsize * 2) {
					star[i][j] = ' ';
				}
				else {
					printStar(i, j, tempsize);
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star[i][j] = ' ';
		}
	}

	printStar(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star[i][j];
		}
		cout << "\n";
	}

}