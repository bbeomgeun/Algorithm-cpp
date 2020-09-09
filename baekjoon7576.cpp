#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int farm[1001][1001], N, M, input,X, Y, dis[1001][1001], result ;
bool check[1001][1001];

int xPos[4] = {1, -1, 0, 0};
int yPos[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> starting;
queue<pair<int, int>> q;

void bfs(int N, int M, queue<pair<int, int>> & start) {
	if (start.empty()) {
		result = 0;
	}
	
	
	while(!start.empty()) {
		int startX = start.front().first;
		int startY = start.front().second;
		start.pop();
		q.push(make_pair(startX, startY));
		check[startX][startY] = true;
	} // start 포인트 q에 push

	while (!q.empty()) {
		X = q.front().first;
		Y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tempX = X + xPos[i];
			int tempY = Y + yPos[i];
			
			if (farm[tempX][tempY] == 0 && !check[tempX][tempY] && tempX > 0 && tempY > 0 && tempX <= N && tempY <= M) {
				check[tempX][tempY] = true;
				q.push(make_pair(tempX, tempY));
				dis[tempX][tempY] = dis[X][Y] + 1;
			}
		}
	}
	int max = 0; 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (max < dis[i][j])
				max = dis[i][j];
		}
	}
	result = max;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (farm[i][j] == 0 && !check[i][j])
				result = -1;
		}
	}
	
}


int main() { // start는 1이 써져있는 곳 모두
	cin >> M >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input;
			farm[i][j] = input;
			if (input == 1) {
				starting.push(make_pair(i, j));
			}
		}
	}
	bfs(N, M, starting);
	cout << result;

}