#include <iostream>
#include <algorithm>

using namespace std;

int N, M, input, arr[8], result[8];

void backTracking(int depth, int next) {
	if (M == depth) {
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	for (int k = next; k < N; k++) {
		result[depth] = arr[k];
		backTracking(depth + 1, k+1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
	}
	sort(arr, arr + N);
	backTracking(0, 0);
	return 0;
}