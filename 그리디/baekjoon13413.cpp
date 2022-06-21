#include <iostream>
#include <cmath>

using namespace std;

int t, n;
string before, after;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> before >> after;

		int w = 0;
		int b = 0;

		for (int i = 0; i < n; i++) {
			if (before[i] == 'W' && after[i] == 'B') {
				w++;
			}
			else if (before[i] == 'B' && after[i] == 'W') {
				b++;
			}
		}

		cout << max(w, b) << "\n";
	}
}