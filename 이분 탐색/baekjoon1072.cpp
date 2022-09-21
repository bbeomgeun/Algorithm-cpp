#include <iostream>

using namespace std;

long long x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> y;
	long long before = y * 100 / x;
	long long l = 1, r = x;
	long long answer = 0;

	if (before >= 99) {
		cout << -1;
		return 0;
	}
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long after = (y + mid) * 100 / (x + mid);
		if (after > before) {
			answer = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << answer;
}