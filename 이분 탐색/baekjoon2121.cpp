#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

typedef pair<int, int> pii;

int n, x, y, a, b, answer;
vector<pii> v;
set<pii> s;

int main() {
	cin >> n >> a >> b;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
		s.insert({ x,y });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int curX = v[i].first;
		int curY = v[i].second;

		int nx = curX + a;
		int ny = curY + b;

		//if (s.find({ curX, ny }) == s.end()) continue;
		//if (s.find({ nx, curY }) == s.end()) continue;
		//if (s.find({ nx, ny }) == s.end()) continue;

		if (!binary_search(v.begin(), v.end(), make_pair( curX, ny))) continue;
		if (!binary_search(v.begin(), v.end(), make_pair(nx, curY))) continue;
		if (!binary_search(v.begin(), v.end(), make_pair(nx, ny ))) continue;

		answer++;
	}

	cout << answer;
}