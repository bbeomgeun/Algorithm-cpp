#include <iostream>
#include <algorithm>
using namespace std;

bool check[10000];
int N, M, arr[8], input[8];

void backTracking(int depth) {
	if (M == depth) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int j = 0; j < N; j++) {
		if (!check[input[j]]) {
			check[input[j]] = true;
			arr[depth] = input[j];
			backTracking(depth + 1);
			check[input[j]] = false;
		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input, input + N);
	backTracking(0);
}