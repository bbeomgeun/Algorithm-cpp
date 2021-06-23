#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M, one, two, check[32001];
vector<int> v[32001];
stack<int> st;

void DFS(int start) {
	check[start] = true;

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!check[next]) {
			DFS(next);
		}
	}
	st.push(start);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> one >> two;
		v[one].push_back(two);
	}
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			DFS(i);
		}
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}