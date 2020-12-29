#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> v;
int n;
string s;

bool compare(string& a, string& b) {
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int flag = false;
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == s) {
				flag = true;
				break;
			}
		}
		if(!flag)
			v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}