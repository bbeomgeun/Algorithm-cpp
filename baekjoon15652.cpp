#include <iostream>
using namespace std;

int M, N, arr[9];
bool check[9];

void backTracking(int n, int m, int depth, int next) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = next; i <= N; i++) {
			arr[depth] = i;
			backTracking(n, m, depth + 1, i);
	}
}

int main() {
	cin >> N >> M;
	backTracking(N, M, 0, 1);
}