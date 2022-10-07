#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string before, after;

bool answer = false;

void DFS(int depth, int target, string cur) {
	if (answer)
		return;
	if (depth == target) {
		if (cur == before) answer = true;
		return;
	}
	if(cur.back() == 'A')
		DFS(depth + 1, target, cur.substr(0, cur.size()-1));
	if (cur.front() == 'B') {
		string re = cur.substr(1, cur.size());
		reverse(re.begin(), re.end());
		DFS(depth + 1, target, re);
	}
}

int main() {
	cin >> before >> after;
	DFS(0, after.size() - before.size(), after);
	cout << answer;
}