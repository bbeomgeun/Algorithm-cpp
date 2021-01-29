#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long num;
map<long long, int> m;
vector<long long> v;
vector < pair<int, long long>> v2;

bool compare(pair<int, long long>& a, pair<int, long long>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else
		return a.first > b.first;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		m[num]++;
		v.push_back(num);
	}

	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		v2.push_back(make_pair(m[v[i]], v[i]));
	}
	sort(v2.begin(), v2.end(), compare);

	cout << v2[0].second;

}