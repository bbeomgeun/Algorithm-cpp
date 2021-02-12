#include <iostream>
#include <cmath>
using namespace std;

int n, arr[9], parr[9], result;
bool check[9];

void permutation(int depth) {
	if (depth == n) {
		int temp = 0;
		for (int i = 0; i < n-1; i++) {
			temp += abs(parr[i] - parr[i + 1]);
		}
		result = max(result, temp);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			parr[depth] = arr[i];
			permutation(depth + 1);
			check[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	permutation(0);

	cout << result;
}