#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, check[27];
string s, temp;

void anagram(string s,int depth) {
	if (depth == s.size()) {
		cout << temp<<"\n";
		return;
	}

	for (int i = 0; i < 26 ; i++) {
		if (check[i]) {
			check[i]--;
			temp.push_back(i+'a');
			anagram(s, depth + 1);
			temp.pop_back();
			check[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		
		for (int i = 0; i < s.size(); i++) {
			check[s[i] - 'a']++;
		}
		anagram(s, 0);
		
		temp.clear();
		for (int i = 0; i < 26 ; i++) {
			check[i] = 0;
		}
	}
}