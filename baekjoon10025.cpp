#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001], n, k, ice, x;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> ice >> x;
		arr[x] = ice;
	}

	int l = 0; int r = 0;
	int sum =0;
	int mx = 0;

	for (int i = 0; i <= 1000000; i++) {
		if (i > 2 * k + 1) {
			sum -= arr[l];
			l++;
		}
		sum += arr[i];
		mx = max(mx, sum);
	}

	cout << mx;

}