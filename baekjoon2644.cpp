#include <iostream>
#include <vector>

using namespace std;
int N, a, b, m, x, y, cal[101];
vector<int> v[101];
bool check[101];

void DFS(int start, int end) {
	check[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		int tempX = v[start][i];
		if (!check[tempX]) {
			cal[tempX] = cal[start] + 1;
			check[tempX] = true;
			DFS(tempX, end);
		}
	}
}

int main() {
	cin >> N>>a>>b>>m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(a, b);
	if (!cal[b])
		cout << -1;
	else
		cout << cal[b];
}