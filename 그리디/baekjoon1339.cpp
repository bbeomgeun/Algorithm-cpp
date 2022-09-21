#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
string s;
vector<string> stringList;
int answer = 0;
int alphabet[26];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		stringList.push_back(s);
	}

	for (int i = 0; i < stringList.size(); i++) {
		reverse(stringList[i].begin(), stringList[i].end());
		for (int j = 0; j < stringList[i].size(); j++) {
			char character = stringList[i][j];
			alphabet[character - 'A'] += pow(10, j);
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] != 0)
			v.push_back(alphabet[i]);
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i = 0, k = 9; i < v.size(); i++, k--) {
		answer += v[i] * k;
	}
	cout << answer;
}