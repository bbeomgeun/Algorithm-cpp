#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int N, M;
string name;
unordered_map<string, string> m;
unordered_map<string, string> m2;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		ios::sync_with_stdio(false);
		cin.tie(0);
		cin >> name;
		m.insert(make_pair(name, to_string(i)));
		m2.insert(make_pair(to_string(i), name));
	}

	for (int i = 0; i < M; i++) {
		cin >> name;
		if (m.count(name)) {
			cout << m[name] << "\n";
		}
		else {
			cout << m2[name] << "\n";
		}
	}
}
