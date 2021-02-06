#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int k, n;
long long result, num, temp, bound, arr[10001];
int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		bound = max(bound, arr[i]);
	}

	long long start = 1;
	long long end = bound;
	while (1) {
		num = 0;
		if (start > end) {
			break;
		}
		temp = (start + end) / 2;
		for (int i = 0; i < k; i++) {
			num += arr[i] / temp;
		}
		if (num >= n) {
			start = temp + 1;
		}
		else if (num < n) {
			end = temp - 1;
		}
	}

	cout << end;
}