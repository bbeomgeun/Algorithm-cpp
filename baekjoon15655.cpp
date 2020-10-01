#include <iostream>
#include <algorithm>

using namespace std;

int N, M, input, arr[8], result[8];
bool check[10001];

void backTracking(int depth, int next) {
	if (M == depth) {
		for (int i = 0; i < N; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	for (int k = next; k < N; k++) {
		if (!check[arr[k]]) {
			check[arr[k]] = true;
			result[depth] = arr[k];
			backTracking(depth + 1, next + 1);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
	}
	sort(arr, arr + 8);
	backTracking(0, 0);
	return 0;
}