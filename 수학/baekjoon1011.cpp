#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int T, x, y, answer;

int main() {

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> x >> y;
		int cnt = 0;
		int answer = 0;
		int diff = y - x;
		int d = sqrt(diff);
		if (diff > pow(d, 2) + d) {
			answer = d * 2 + 1;
		}
		else if (diff > pow(d, 2)) {
			answer = d * 2;
		}
		else if (diff == pow(d, 2)) {
			answer = d * 2 - 1;
		}
		
		cout << answer << "\n";
	}
}