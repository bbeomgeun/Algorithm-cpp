#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, num;
deque<int> result;

int main() {
	cin >> n;
	vector<int> v(n);

	for (int i = 1; i <= n; i++) {
		cin >> v[n - i];
	}

	for (int i = 0; i < n; i++) {
		if (v[i] == 1) {
			result.push_front(i + 1);
		}
		else if (v[i] == 3) {
			result.push_back(i + 1);
		}
		else {
			result.push_front(result.front());
			result[1] = i + 1;
		}
	}

	for (auto k : result) {
		cout << k << " ";
	}
}