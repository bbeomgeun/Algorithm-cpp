#include <iostream>
#include <cmath>
using namespace std;

int n, result;

int main() {
	cin >> n;
	if (n < 0) {
		result = 31;
	}
	else if (n == 0)
		result = 0;
	else {
		result = floor(log2(n));
	}

	cout << result + 1;
}