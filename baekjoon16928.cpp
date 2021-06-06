#include <iostream>
#include <queue>

using namespace std;

int N, M, x, y;
int moving[101], record[101];

void BFS(int start) {
	queue < pair<int, int>> q;
	q.push(make_pair(start, 0));
	record[start] = 0;

	while (!q.empty()) {
		int now = q.front().first;
		int count = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int tempCount = count;
			if (now + i > 100)
				continue;
			int next = now + i;
			tempCount++;
			if (moving[next] != 0) {
				next = moving[next];
			}
			if (record[next] > tempCount) {
				record[next] = tempCount;
				q.push(make_pair(next, tempCount));
			}
		}
	}
	
}


int main() {
	cin >> N >> M;
	for (int i = 1; i <= 100; i++) {
		record[i] = 987654321;
	}
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		moving[x] = y;
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		moving[x] = y;
	}

	BFS(1);

	cout << record[100];
}