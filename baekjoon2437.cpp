#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, num;
vector<int> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	int sum = 0;
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (sum + 1 < v[i]) {
			break;
		}
		sum += v[i];
	}

	cout << sum + 1;
}