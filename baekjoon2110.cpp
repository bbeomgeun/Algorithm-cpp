#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, x;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int start = 1;
	int end = v[n-1];

	while (start <= end) {
		int cnt = 1;
		int mid = (start + end) / 2;


		int t = v[0];
		for (int i = 1; i < n; i++) {
			if (v[i] - t >= mid) {
				cnt++;
				t = v[i];
			}
		}
		if (cnt >= c) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << end;
}