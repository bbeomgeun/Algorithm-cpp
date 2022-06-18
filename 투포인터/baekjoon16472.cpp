#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
string s;
unordered_map<char, int> m;

int main() {
	cin >> n >> s;

	int l = 0;
	int r = 0;
	int answer = 0;

	m[s[r]]++;

	while (l <= r && r < s.size()) {
		if (m.size() <= n) {
			r++;
			m[s[r]]++;
			if(m.size() <= n && r < s.size())
				answer = max(answer, r - l + 1);
		}
		else {
			char deleteTarget = s[l];
			m[deleteTarget]--;
			if (m[deleteTarget] == 0)
				m.erase(deleteTarget);
			l++;
		}
	}

	cout << answer;
}