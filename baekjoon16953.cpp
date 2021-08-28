#include <iostream>
#include <queue>
#define MAX 1000000000

using namespace std;

int from, to;
typedef pair<int, int> pii;
queue<pii> q;

int BFS(int cur, int to) {
	q.push({ cur, 0 });

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == to) {
			return cnt + 1;
		}
		int nx = x * 2;
		if (nx <= to) {
			q.push({ nx,cnt + 1 });
		}
		nx = x * 10 + 1;
		if (nx <=to) {
			q.push({ nx,cnt + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> from >> to;

	cout<< BFS(from, to);
}