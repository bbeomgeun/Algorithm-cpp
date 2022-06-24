#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, num, total;
vector<int> v;
vector<int> diff;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; i++) {
		diff.push_back(v[i + 1] - v[i]);
		total += (v[i + 1] - v[i]);
	}

	sort(diff.begin(), diff.end());
	reverse(diff.begin(), diff.end());

	for (int i = 0; i < k-1; i++) {
		total -= diff[i];
	}

	cout << total;
}