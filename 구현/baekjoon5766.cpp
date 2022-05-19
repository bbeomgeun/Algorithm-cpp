#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, num;

bool compare(pii& a, pii& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main() {
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			return 0;
		}
		unordered_map<int, int> cnt;
		vector<pii> v;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> num;
				cnt[num]++;
			}
		}

		for (auto k : cnt) {
			v.push_back({ k.second , k.first});
		}

		sort(v.begin(), v.end(), compare);

		int ans = v[1].first;

		for (int i = 1; i < v.size(); i++) {
			if (v[i].first == ans)
				cout << v[i].second << " ";
			else {
				break;
			}
		}
		cout << "\n";
	}
}