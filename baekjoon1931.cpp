#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, start, finish;
vector<pair<int, int>> v;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> finish;
		v.push_back(make_pair(start, finish));
	}
	
	sort(v.begin(), v.end(), compare);

	int time1 = v[0].second;
	int cnt = 1;

	for (int i = 1; i < v.size(); i++) {
		if (v[i].first >= time1) {
			cnt++;
			time1 = v[i].second;
		}
	}

	cout << cnt;
}