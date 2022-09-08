#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2000000000

using namespace std;

int n, m, num;
vector<int> v;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int l = 0;
	int r = 0;
	int answer = MAX;

	while (l <= r && r < n) {
		int lNum = v[l];
		int rNum = v[r];
		int diff = rNum - lNum;

		if (diff == m) {
			answer = diff;
			break;
		}
		else if (diff < m) {
			r++;
		}
		else if (diff > m) {
			answer = min(answer, diff);
			l++;
		}
	}

	cout << answer;
}