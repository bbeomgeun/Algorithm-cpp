#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1001], dp[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	int mx = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (dp[i] > mx)
			mx = dp[i];
	}
	cout << mx;
}