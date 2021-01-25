#include <iostream>
using namespace std;

int N, arr[1001], dp[1001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	int max = arr[0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
		if (max < dp[i])
			max = dp[i];
	}
	cout << max;
}