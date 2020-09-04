#include <iostream>
#include <algorithm>

using namespace std;

int N, A[50], B[50], input, result;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> input;
		A[i] = input;
}
	for (int i = 0; i < N; i++) {
		cin >> input;
		B[i] = input;
	}

	sort(A, A + N);
	sort(B, B + N, compare);

	for (int i = 0; i < N; i++) {
		result += (A[i] * B[i]);
	}
	cout << result;
}