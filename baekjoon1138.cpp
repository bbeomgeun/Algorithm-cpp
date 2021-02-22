#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
vector<pair<int, int>> v;

bool compare(pair<int, int>& a, pair<int, int>& b) {
		return a.first > b.first;
}


int main() {
	cin >> n;

	for (int height = 0; height < n; height++) {
		cin >> cnt;
		v.push_back(make_pair(height+1,cnt));
	}
	sort(v.begin(), v.end());

	for (int i = 0;i < n; i++) {
		int cnt = 0;
		for (int j = 0; j <= i; j++) {
			if (cnt == v.back().second) {
				v.insert(v.begin() + j, v.back());
				v.erase(v.end() - 1);
				break;
			}
			if (v.back() < v[j])
				cnt++;
		}
	}

	for (auto i : v) {
		cout << i.first << " ";
	}
}