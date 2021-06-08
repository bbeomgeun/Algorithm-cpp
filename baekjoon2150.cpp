#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int V, E,from, to, check[10001];
stack<int> s;
vector<int> v[10001];
vector<int> v2[10001];

void DFS(int start) {
	check[start] = true;

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!check[next]) {
			DFS(next);
		}
	}
	s.push(start);
}

void DFS2(int start, vector<int> & v) {
	check[start] = true;

	for (int i = 0; i < v2[start].size(); i++) {
		int next = v2[start][i];
		if (!check[next]) {
			DFS2(next, v);
		}
	}
	v.push_back(start);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> V >> E;
	for (int e = 0; e < E; e++) {
		cin >> from >> to;
		v[from].push_back(to); // G
		v2[to].push_back(from); // G transpose
	}
	for (int i = 1; i <= V; i++) {
		if (!check[i])
			DFS(i);
	}

	for (int i = 1; i <= V; i++) {
		check[i] = false;
	}
	vector<vector<int>> answer;
	while (!s.empty()) {
		int num = s.top();
		s.pop();
		if (!check[num]) {
			vector<int> tempV;
			DFS2(num, tempV);
			sort(tempV.begin(), tempV.end());
			tempV.push_back(-1);
			answer.push_back(tempV);
		}
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}