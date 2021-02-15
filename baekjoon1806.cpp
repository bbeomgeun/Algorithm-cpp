#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001], n, s, sum, cnt, l, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int result = 100001;

	while (1) {
		if (sum < s) {
			if (r == n) {
				break;
			}
			sum += arr[r];
			r++;
		}
		else {
			result = min(result, r - l);
			sum -= arr[l];
			l--;
		}
	}

	if (result == 100001) {
		cout << 0;
	}
	else
		cout << result;
}