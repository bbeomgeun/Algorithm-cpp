#include <iostream>
using namespace std;

int T, N, cycle, arr[1001], check[1001], outCheck[1001];

void DFS(int start) {
	if (check[start])
		return;
	check[start] = true;

	int next = arr[start];

	if (!check[next]) {
		DFS(next);
	}
	else if (!outCheck[next]) {
		cycle++;
	}
	outCheck[next] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		cycle = 0;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= N; i++) {
			if (!check[i]) {
				DFS(i);
			}
		}

		for (int i = 1; i <= N; i++) {
			arr[i] = 0;
			check[i] = 0;
			outCheck[i] = 0;
		}
		cout << cycle<<"\n";
	}
}