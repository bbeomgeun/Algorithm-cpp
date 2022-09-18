#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

vector<int> points;
vector<pii> lines;
int n, m, num, from, to;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		points.push_back(num);
	}

	sort(points.begin(), points.end());

	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		int left = 0;
		int right = n - 1; 
		int leftIndex = 0;
		int rightIndex = 0;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (points[mid] < from) {
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
		leftIndex = left;

		left = 0, right = n - 1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (points[mid] > to) {
				right = mid - 1;
			}
			else
				left = mid + 1;
		}

		rightIndex = right;

		cout << rightIndex - leftIndex+1 << "\n";
	}
}