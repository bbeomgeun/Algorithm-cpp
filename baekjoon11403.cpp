#include <iostream>
#include <vector>
using namespace std;

int n, num, result[101][101], check[101] ;
vector<int> v[101];

void dfs(int now, int start) {

	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!check[next]) {
			check[next] = true;
			result[now][next] = 1;
			result[start][next] = 1;
			dfs(now, next);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			if (num == 1) {
				v[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		dfs(i,i);
		for (int i = 1; i <= n; i++) {
			check[i] = false;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

}