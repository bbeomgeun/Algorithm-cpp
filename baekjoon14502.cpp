#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, num, wall, check[9][9], range[9][9], Max, disX[4] = { 1,-1,0,0 }, disY[4] = { 0, 0, 1, -1 };
vector < pair<int, int>> virus;
vector < pair<int, int>> noWall;

void VirusBFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int tempX = q.front().first;
		int tempY = q.front().second;
		check[tempX][tempY] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = tempX + disX[i];
			int Y = tempY + disY[i];
			if (X >= 0 && X < N && Y >= 0 && Y < M) {
				if (!check[X][Y] && range[X][Y] == 0) {
					check[X][Y] = 1;
					q.push(make_pair(X, Y));
				}
			}
		}
	}
}

void clearCheck() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			range[i][j] = num;
			if (num == 0) {
				noWall.push_back(make_pair(i, j));
			}
			else if (num == 2)
				virus.push_back(make_pair(i, j));
		}
	}
	int noWallSize = noWall.size();
	for (int i = 0; i < noWallSize-2; i++) {
		pair<int, int> temp1 = noWall[i];
		range[temp1.first][temp1.second] = 1;
		// 1차 벽 세우기
		for (int j = i + 1; j < noWallSize-1; j++) {
			pair<int, int> temp2 = noWall[j];
			range[temp2.first][temp2.second] = 1;
			// 2차 벽세우기
			for (int k = j + 1; k < noWallSize; k++) {
				pair<int, int> temp3 = noWall[k];
				range[temp3.first][temp3.second] = 1;
				// 3차 벽세우기
				for (int vir = 0; vir < virus.size(); vir++) {
					VirusBFS(virus[vir].first, virus[vir].second);
					// 벽 세우고 Virus 퍼진 상태
				}
				int cnt = 0;
				for (int Xx = 0; Xx < N; Xx++) {
					for (int Yy = 0; Yy < M; Yy++) {
						if (range[Xx][Yy] == 0 && !check[Xx][Yy]){
							cnt++;
							Max = max(Max, cnt);
						}
					}
				}
				clearCheck();
				range[temp3.first][temp3.second] = 0;
				//계속 세번째 벽 위치만 바뀌므로 세번째만 해제해준다.
			}
			range[temp2.first][temp2.second] = 0;
			// 세번째 모두 돌면 두번째 벽 바꿔줘야하므로 해제해준다.
		}
		range[temp1.first][temp1.second] = 0;
		// 첫번째 벽 해제
	}

	cout << Max;
}