// 포도주문제

#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001], dp[10001], n, num;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(max(arr[0] + arr[1], arr[0] + arr[2]), arr[1]+arr[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i]);
	}

	cout << dp[n - 1];
	
	
}