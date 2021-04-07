#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, answer, carr[21], arr[21][21];

void recur(int next, int depth) {
	if (depth == n / 2) {
		int start = 0;
		int link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (carr[i] && carr[j]) {
					start += arr[i][j];
				}
				if (!carr[i] && !carr[j]) {
					link += arr[i][j];
				}
			}
		}
		answer = min(answer, abs(start-link));
	}
	else {
		for (int i = next; i <= n; i++) {
			carr[i] = true;
			recur(i + 1, depth + 1);
			carr[i] = false;
		}
	}
}


int main() {
	cin >> n;
	answer = 987654321;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

 	recur(1, 0);

	cout << answer;
}