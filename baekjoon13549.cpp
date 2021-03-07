#include <iostream>
#include <queue>

using namespace std;

int N, K;
deque<int> q;
int arr[100001], xmove[2] = { 1, -1 };

void BFS(int start, int target) {
	arr[start] = 0;
	q.push_back(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop_front();

		if (x == target) {
			return;
		}
		int nextX = 0;

		nextX = 2 * x;
		if (nextX >= 0 && nextX <= 100000) {
			if (arr[nextX] == -1) {
				arr[nextX] = arr[x];
				q.push_front(nextX);
			}
		}

		for (int i = 0; i < 2; i++) {
			nextX = x + xmove[i];
			if (nextX >= 0 && nextX <= 100000) {
				if (arr[nextX] == -1) {
					arr[nextX] = arr[x] + 1;
					q.push_back(nextX);
				}
			}
		}
	}
}
int main() {
	cin >> N >> K;

	for (int i = 0; i <= 100000; i++) {
		arr[i] = -1;
	}


	BFS(N, K);

	cout << arr[K];

}