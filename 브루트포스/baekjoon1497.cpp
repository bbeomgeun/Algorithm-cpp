#include <iostream>

using namespace std;

int n, m, arr[11][51], record[11], cnt, answer = 11;
string name, info;

void func(int depth, int n, string path) {
	if (depth  == n) {
		int temp = 0;
		int tempCnt = 0;
		bool check[51] = { false, };
		for (int i = 0; i < n; i++) {
			if (path[i] == 'O') {
				tempCnt++;
				for (int j = 0; j < m; j++) {
					if (arr[i][j]) {
						check[j] = true;
					}
				}
			}
		}

		for (int i = 0; i < m; i++) {
			if (check[i])
				temp++;
		}
		if (cnt <= temp) {
			cnt = temp;
			answer = min(answer, tempCnt);
		}
		return;
	}

	func(depth + 1, n, path + "O");
	func(depth + 1, n, path + "X");
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name >> info;
		for (int j = 0; j < info.size(); j++) {
			if (info[j] == 'Y') {
				arr[i][j] = true;
			}
			else {
				arr[i][j] = false;
			}
		}
	}
	func(0, n,"");

	if (answer == 0)
		cout << -1;
	else
		cout << answer;
}