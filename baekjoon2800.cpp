#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

stack<int> pairStack;
vector<pair<int, int>> pairVector;
int check[11], stringCheck[201];
string s;
set<string> answer;

void combination(string s, int depth, int next, int to) {
	if (depth == to+1)
		return;
	if (depth > 0) {
		string temp = "";
		for (int i = 0; i < s.size(); i++) {
			if (!stringCheck[i])
				temp += s[i];
		}
	
		answer.insert(temp);
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
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			pairStack.push(i);
		}
		else if (s[i] == ')') {
			pairVector.push_back({ pairStack.top(), i });
			pairStack.pop();
		}
	}

	combination(s, 0, 0, pairVector.size());

	for (auto k : answer)
		cout << k << "\n";
}