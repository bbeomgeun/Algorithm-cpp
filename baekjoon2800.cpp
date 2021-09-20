#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> pairStack;
vector<pair<int, int>> pairVector;
int check[11], stringCheck[201];
string s;
vector<string> v;

void combination(string s, int depth, int next, int to) {
	if (depth == to)
		return;
	if (depth > 0) {
		string temp = "";
		for (int i = 0; i < s.size(); i++) {
			if (!stringCheck[i])
				temp += s[i];
		}
	
		v.push_back(temp);
	}
	for (int i = next; i < to; i++) {
		if (!check[i]) {
			check[i] = true;
			stringCheck[pairVector[i].first] = true;
			stringCheck[pairVector[i].second] = true;
			combination(s, depth + 1, i + 1, to);
			stringCheck[pairVector[i].first] = false;
			stringCheck[pairVector[i].second] = false;
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); 	cin.tie(0);
	cin >> s;
	int cnt = 0;
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			pairStack.push(i);
			cnt++;
			continue;
		}
		else if (s[i] == ')') {
			pairVector.push_back({ pairStack.top(), i });
			pairStack.pop();
			continue;
		}
		else
			temp += s[i];
	}
	v.push_back(temp);

	combination(s, 0, 0, cnt);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto k : v)
		cout << k << "\n";
}