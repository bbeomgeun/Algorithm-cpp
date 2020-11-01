#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001], num;

int main() {
	cin >> num;
	for (int i = 2; i <= num; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0) {
			DP[i] = min(DP[i], DP[i / 2]+1);
		}
		if (i % 3 == 0) {
			DP[i] = min(DP[i], DP[i / 3]+1);
		}
	}
	cout << DP[num];
}