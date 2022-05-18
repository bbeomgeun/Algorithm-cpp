#include <iostream>
using namespace std;

int T, n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> m;
		long long answer = 1;
		if (n == m)
			cout << answer<<"\n";
		else {
			if (n > m / 2) {
				n = m - n;
			}
			for (int i = 1; i <= n; i++) {
				answer *= m;
				m -= 1;
			}
			for (int i = 1; i <= n; i++) {
				answer /= i;
			}
			cout << answer << "\n";
		}
	}
}