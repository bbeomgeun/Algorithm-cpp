#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int n, m, r, item[101], arr[101][101], from, to, cost;

int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < r; i++) {
		cin >> from >> to >> cost;
		arr[from][to] = cost;
		arr[to][from] = cost;
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

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		int temp = item[i];
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] <= m) {
				temp += item[j];
			}
		}
		answer = max(answer, temp);
	}
	cout << answer;

}

