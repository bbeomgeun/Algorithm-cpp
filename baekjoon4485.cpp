#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

int n, arr[126][126], xmove[4] = { 1, -1, 0, 0 }, ymove[4] = { 0, 0, 1, -1 };
int record[126][126];

int BFS(int startX, int startY, int targetX, int targetY) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push(make_pair(arr[startX][startY], make_pair(startX, startY)));
	record[startX][startY] = arr[startX][startY];

	while (!q.empty()) {
		int distance = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();

		if (x == targetX && y == targetY) {
			return distance;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + xmove[i];
			int ny = y + ymove[i];
			int nextDistance = distance + arr[nx][ny];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (record[nx][ny] > nextDistance) {
					record[nx][ny] = nextDistance;
					q.push(make_pair(nextDistance, make_pair(nx, ny)));
				}
			}
		}
	}
}

int main() {
	int phase = 0;
	while (1) {
		phase++;
		cin >> n;
		if (n == 0)
			return 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				record[i][j] = INF;
			}
		}

		int result = BFS(0, 0, n - 1, n - 1);

		cout << "Problem " << phase << ": " << result << "\n";
	}

}