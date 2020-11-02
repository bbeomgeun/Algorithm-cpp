#include <iostream>
#include <queue>
using namespace std;

char field [101][101] ;
string input;
bool check[101][101], check2[101][101];
int xPos[4] = { 1, -1, 0, 0 }, yPos[4] = { 0,0,1,-1 }, N, cnt, cnt2;

void BFS(int i, int j, char c) {
	cnt++;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int tempX = q.front().first;
		int tempY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = tempX + xPos[i];
			int Y = tempY + yPos[i];
			if (X >= 0 && Y >= 0 && X < N && Y < N && !check[X][Y] && field[X][Y] == c) {
				q.push(make_pair(X, Y));
				check[X][Y] = true;
			}
		}
	}
}

void BFS2(int i, int j, char c) {
	cnt2++;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int tempX = q.front().first;
		int tempY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int X = tempX + xPos[i];
			int Y = tempY + yPos[i];
			if (X >= 0 && Y >= 0 && X < N && Y < N && !check2[X][Y]) {
				if (c == 'R' || c == 'G') {
					if (field[X][Y] == 'R' || field[X][Y] == 'G') {
						q.push(make_pair(X, Y));
						check2[X][Y] = true;
					}
				}
				else {
					if (field[X][Y] == c) {
						q.push(make_pair(X, Y));
						check2[X][Y] = true;
					}
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			field[i][j] = input[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				BFS(i, j, field[i][j]);
			}
			if (!check2[i][j]) {
				BFS2(i, j, field[i][j]);
			}
		}
	}
	cout << cnt<<" "<<cnt2;
}