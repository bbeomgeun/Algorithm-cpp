#include <iostream>

using namespace std;

int n, k, result;
int coin[11];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		while (k >= coin[i]) {
			k -= coin[i];
			result++;
		}
	}
	cout << result;
}