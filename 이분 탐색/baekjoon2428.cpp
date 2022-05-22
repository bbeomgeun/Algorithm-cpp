#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, num;
long long answer;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {

		int l = 0;
		int r = v.size();

		while (l <= r) {
			int mid = (l + r) / 2;
			if (v[mid] < v[i]*0.9) { // 큰 케이스
				l = mid + 1;
			}
			else { // 작으면 키워보기
				r = mid - 1;
			}
		}
		answer += (i - l);
	}
	cout << answer;
}