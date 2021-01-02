#include <iostream>
#include <map>
#include <queue>
using namespace std;

int T,k, N;
string s;

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> k;
		multimap<int, int> m;
		for (int i = 0; i < k; i++) {
			cin >> s >> N;
			if (s == "I") {
				m.insert(make_pair(N, 1));
			}
			else if (s == "D") {
				if (!m.empty()) {
					if (N == 1) {
						m.erase(m.find(m.rbegin()->first));
					}
					else {
						m.erase(m.find(m.begin()->first));
					}
				}
			}
		}
		if (m.empty())
			cout << "EMPTY" << "\n";
		else {
			cout << m.rbegin()->first << " " << m.begin()->first << "\n";
		}
	}
}