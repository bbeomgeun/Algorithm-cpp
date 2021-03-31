#include <iostream>

using namespace std;

int n, arr[65][65];
string s;

void compression(int size, int col, int row) {
	if (size == 1) {
		cout << arr[col][row];
		return;
	}
	else {
		int temp = arr[col][row];
		int flag = true;
		for (int i = col; i < size + col; i++) {
			for (int j = row; j < size + row; j++) {
				if (temp != arr[i][j]) {
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (flag) {
			cout << temp;
		}
		else {
			cout << "(";
			compression(size / 2, col, row);
			compression(size / 2, col, row + size / 2);
			compression(size / 2, col + size / 2, row);
			compression(size / 2, col + size / 2, row + size / 2);
			cout << ")";
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j]-'0';
		}
	}

	compression(n, 0, 0);
}