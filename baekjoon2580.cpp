#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int sudoku[10][10];
vector<pii> v;

bool rowCheck(int num, int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[row][i] == num)
			return false;
	}
	return true;
}

bool colCheck(int num, int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[i][col] == num)
			return false;
	}
	return true;
}

bool boxCheck(int num, int row, int col) {
	int startRow = (row / 3) * 3;
	int startCol = (col / 3) * 3;

	for (int i = startRow; i < startRow + 3; i++) {
		for (int j = startCol; j < startCol + 3; j++) {
			if (sudoku[i][j] == num)
				return false;
		}
	}
	return true;
}

void backTracking(int index) {
	if (index == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	int x = v[index].first;
	int y = v[index].second;

	for (int num = 1; num <= 9; num++) {
		if (rowCheck(num, x, y) && colCheck(num, x, y) && boxCheck(num, x, y)) {
			sudoku[x][y] = num;
			backTracking(index + 1);
			sudoku[x][y] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0)
				v.push_back(make_pair(i, j));
		}
	}
	backTracking(0);
}