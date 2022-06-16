#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, num, answer;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int t = n / 3;

	for (int i = 0; i < t * 3; i += 3) {
		answer += (v[i] + v[i + 1]);
	}

	for (int i = t * 3; i < n; i++) {
		answer += v[i];
	}
	cout << answer;
}