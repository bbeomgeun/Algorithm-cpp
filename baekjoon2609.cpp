#include <iostream>

using namespace std;

int a, b;

int main() {
	cin >> a >> b;
	int big = a >= b ? a : b;
	int small = a <= b ? a : b;
	int max = 0;
	int min = 0;

	int k1 = big;
	int k2 = small;
	while (k2 != 0) {
		int p = k1 % k2;
		k1 = k2;
		k2 = p;
	}

	min = big * small / k1;

	cout << k1 << "\n" << min;

}