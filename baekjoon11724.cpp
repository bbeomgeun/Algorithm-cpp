#include <iostream>
#include <vector>

using namespace std;

int N, M, u, v ,cnt;
bool check[1001];
vector<int> a[1001];

void dfs(int start) {
	check[start] = true;

	for (int i = 0; i < a[start].size(); i++) {
		int temp = a[start][i];

		if (!check[temp]) {
			check[temp] = true;
			dfs(temp);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

}