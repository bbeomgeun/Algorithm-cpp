#include <iostream>
#include <queue>

using namespace std;

int road[100001], cnt[100001], N, K, tempX, walk[2] = { 1, -1 };
bool check[100001];
queue<int> q;

int bfs(int start, int end) {
	
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int X = q.front();
		q.pop();

		if (X == end) {
			return cnt[end];
		}

		for (int i = 0; i < 2; i++) {
			tempX = X + walk[i];

			if (tempX >= 0 && tempX <= 100000 && !check[tempX]) {
				q.push(tempX);
				check[tempX] = true;
				cnt[tempX] = cnt[X] + 1;
			}
		}
		tempX = X * 2;
		if (tempX >= 0 && tempX <= 100000 && !check[tempX]) {
			q.push(tempX);
			check[tempX] = true;
			cnt[tempX] = cnt[X] + 1;
		}
	}
}

int main() {
	cin >> N >> K;
	cout<<bfs(N, K);
}