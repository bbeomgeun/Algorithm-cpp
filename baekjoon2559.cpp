#include <iostream>
#include <algorithm>
using namespace std;

int n, k, arr[100001], lp, rp;


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int mx = 0;
	
	for (int i = 0; i < k; i++) {
		mx += arr[i];
	}
	lp = 0;
	rp = k - 1;

	int temp = mx;
	while (rp != n - 1) {
		rp++;
		temp = temp + arr[rp] - arr[lp];
		lp++;
		mx = max(mx, temp);
	}
	cout << mx;
}