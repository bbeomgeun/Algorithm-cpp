#include <iostream>
#define INF 987654321

using namespace std;

int V, E, a, b, c, arr[401][401];

int main() {
	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}

	int answer = INF;

	for (int i = 1; i <= V; i++) {
		answer = min(answer, arr[i][i]);
	}
	if (answer < INF)
		cout << answer;
	else
		cout << -1;


}