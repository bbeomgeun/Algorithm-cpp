#include <iostream>
#define MAX 1e9
using namespace std;

typedef long long ll;

int n, k;
int l = 1, r = MAX;

ll calculate(int mid) {
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += min(n, mid / i);
	}
	return cnt;
}

int binary_search() {
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int t = calculate(mid);
		if (t >= k) { // k번째보다 더 큼
			ans = mid;
			r = mid - 1;
		}
		else if (t < k) { // k번째보다 작음
			l = mid + 1;
		}
	}
	return ans;
}

int main() {
	cin >> n >> k;
	cout << binary_search();
}