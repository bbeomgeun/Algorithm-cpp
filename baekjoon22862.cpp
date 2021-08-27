#include <iostream>

using namespace std;

int n, k, arr[1000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int l = 0, r = 0, delCnt = 0, answer = 0, evenCnt = 0;

	while (l < n) {
		if (delCnt > k || r == n) {
			answer = max(answer, evenCnt);
			if (arr[l] % 2 == 0)
				evenCnt--;
			else
				delCnt--;
			l++;
		}
		else if (delCnt <= k) {
			if (arr[r] % 2 == 0) {
				evenCnt++;
			}
			else {
				delCnt++;
			}
			r++;
		}
	
	}
	cout << answer;
}