#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, num, answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());


	for (int i = 0; i < v.size(); i++) {
		int target = v[i];

		int l = 0;
		int r = n - 1;

		while (l < r) {
			int sum = v[l] + v[r];
			if (sum == target) {
				if (l == i) l++;
				else if (r == i) r--;
				else {
					answer++;
					break;
				}
			}
			else {
				if (sum > target) r--;
				else if (sum < target) l++;
			}
		}
	}
	cout << answer;
}