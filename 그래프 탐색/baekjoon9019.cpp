#include <iostream>
#include <string>
#include<queue>
#include <deque>

using namespace std;

int n, from, to, check[10001], nx;
typedef pair<int, string> pis;
vector<string> v;

void init() {
	for (int i = 0; i < 10001; i++) {
		check[i] = false;
	}
}

int funcL(int before) {
	if (before < 1000)
		return before * 10;
	else {
		int temp = before / 1000;
		before %= 1000;
		before *= 10;
		return before + temp;
	}
}

int funcR(int before) {
	int temp = before % 10;
	before /= 10;
	return before + 1000 * temp;
}

int funcD(int before) {
	before = (before * 2) % 10000;
	return before;
}

int funcS(int before) {
	if (before == 0) {
		return 9999;
	}
	else {
		return before-1;
	}
}

void BFS(int from, int to, string commands) {
	queue<pis> q;
	q.push({ from, commands });
	check[from] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		string command = q.front().second;
		q.pop();

		if (cur == to) {
			v.push_back(command);
			return;
		}
		nx = funcL(cur);
		if (!check[nx]) {
			check[nx] = true;
			q.push({ nx, command + "L" });
		}
		nx = funcR(cur);
		if (!check[nx]) {
			check[nx] = true;
			q.push({ nx, command + "R" });
		}
		nx = funcD(cur);
		if (!check[nx]) {
			check[nx] = true;
			q.push({ nx, command + "D" });
		}
		nx = funcS(cur);
		if (!check[nx]) {
			check[nx] = true;
			q.push({ nx, command + "S" });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		BFS(from, to, "");
		init();
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}