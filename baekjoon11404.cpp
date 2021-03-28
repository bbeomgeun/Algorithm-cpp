#include <iostream>
#define INF 987654321

using namespace std;

int n, m, arr[101][101], from, to, cost;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		if(arr[from][to] > cost)
			arr[from][to] = cost;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k)
					continue;
				if (arr[j][k] > arr[j][i] + arr[i][k])
					arr[j][k] = arr[j][i] + arr[i][k];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}