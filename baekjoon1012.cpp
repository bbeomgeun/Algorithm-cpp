#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, M, N, K, X, Y, xmove[4] = { 1, -1, 0, 0 }, ymove[4] = { 0, 0, 1, -1 };
int farm[51][51];
bool check[51][51];

void BFS(int row, int col) {
	queue<pair<int, int>> q;
	check[row][col] = true;
	q.push(make_pair(row, col));

	while (!q.empty()) {
		int tempX = q.front().first;
		int tempY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = tempX + xmove[i];
			int Y = tempY + ymove[i];

			if (X >= 0 && X <= N - 1 && Y >= 0 && Y <= M - 1) {
				if (farm[X][Y] == 1 && !check[X][Y]) {
					q.push(make_pair(X, Y));
					check[X][Y] = true;
				}
			}
		}
	}
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;
		vector < pair<int, int>> v;
		int cnt = 0;
		for(int i = 0 ; i < K ; i++){
			cin >> X >> Y;
			v.push_back(make_pair(Y, X));
			farm[Y][X] = 1;
		}
		for (int i = 0; i < v.size(); i++) {
			int tempx = v[i].first;
			int tempy = v[i].second;
			if (!check[tempx][tempy]) {
				cnt++;
				BFS(tempx, tempy);
			}
		}
		cout << cnt<<"\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				check[i][j] = false;
				farm[i][j] = 0;
			}
		}
	}

}