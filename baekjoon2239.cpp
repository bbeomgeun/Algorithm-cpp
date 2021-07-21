#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
string s;
vector<pii> empty_space;
int arr[10][10];

bool rowCheck(int row, int num) {
	for (int i = 0; i < 9; i++) {
		if (arr[row][i] == num)
			return false;
	}
	return true;
}

bool colCheck(int col, int num) {
	for (int i = 0; i < 9; i++) {
		if (arr[i][col] == num)
			return false;
	}
	return true;
}

bool squareCheck(int row, int col, int num) {
	int x = row / 3 * 3;
	int y = col / 3 * 3;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (arr[i][j] == num)
				return false;
		}
	}
	return true;
}

void sudoku(int pos) {
	if (pos == empty_space.size()){
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
	
	int x = empty_space[pos].first;
	int y = empty_space[pos].second;

	for (int num = 1; num <= 9; num++) {
		if (rowCheck(x, num) && colCheck(y, num) && squareCheck(x, y, num)) {
			arr[x][y] = num;
			sudoku(pos + 1);
			arr[x][y] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		cin >> s;
		for (int j = 0; j < 9; j++) {
			arr[i][j] = s[j] - '0';
			if (arr[i][j] == 0)
				empty_space.push_back(make_pair(i, j));
		}
	}

	sudoku(0);

}