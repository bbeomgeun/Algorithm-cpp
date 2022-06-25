#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string s;
unordered_set<string> ans;

void dfs(int depth, int L, int R, string target, string path, string cur) {
	if (depth == target.size() && target == cur) {
		ans.insert(path);
		return;
	}

	if (L - 1 >= 0) {
		string t = s[L - 1] + cur;
		dfs(depth + 1, L - 1, R, target, path + " " + t, t);
	}
	if (R + 1 <= target.size() - 1) {
		string t = cur + s[R + 1];
		dfs(depth + 1, L, R + 1, target, path + " " + t, t);
	}
}

int main() {
	cin >> s;

	for(int i = 0 ; i <s.size() ; i++){
		string cur = "";
		cur += s[i];
		dfs(1, i, i, s, cur, cur);
	}

	cout << ans.size();
}