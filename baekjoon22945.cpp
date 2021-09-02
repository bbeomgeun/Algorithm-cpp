#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 0, right = n-1, answer = 0;

	while (left < right) {
		answer = max(answer, min(arr[right], arr[left]) * (right - (left+1)));
		if (arr[left] > arr[right]) {
			right--;
		}
		else
			left++;
	}
	cout << answer;
}