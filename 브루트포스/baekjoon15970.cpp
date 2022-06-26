#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1e5;

using namespace std;

int n, x, color, answer;
vector<int> v[5001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> color;
		v[color].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int result = MAX;
			int cur = v[i][j];
			if (j - 1 >= 0) {
				result = min(result, abs(cur - v[i][j - 1]));
			}
			if (j + 1 < v[i].size()) {
				result = min(result, abs(cur - v[i][j + 1]));
			}
			answer += result;
		}
	}
	cout << answer;
}