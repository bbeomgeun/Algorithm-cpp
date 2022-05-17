#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1e9*2

using namespace std;

int n, sz;
vector<int> v;
vector<int> numList;
int answer = MAX;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sz;
		v.push_back(sz);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n - 3; i++) {
		for (int j = 3; j < n; j++) {
			int fix = v[i] + v[j];
			int left = i + 1;
			int right = j - 1;

			while (left < right) {
				int s = (v[left] + v[right]);
				answer = min(answer, abs(fix - s));

				if (fix >= s) {
					left++;
				}
				else {
					right--;
				}
			}
		}
	}
	cout << answer;
}