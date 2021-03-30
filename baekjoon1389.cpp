#include <iostream>
#define INF 987654321
using namespace std;

int n, m, a, b, arr[101][101];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k)
					continue;
				else
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}

	int answer = INF;
	int result = 0;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			else
				temp += arr[i][j];
		}
		if (answer > temp) {
			answer = temp;
			result = i;
		}
	}
	cout << result;
}