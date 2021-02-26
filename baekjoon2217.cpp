#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, weight;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weight;
		v.push_back(weight);
	}

	sort(v.begin(), v.end());

	int mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, v[i] * (n - i));
	}

	cout << mx;
}