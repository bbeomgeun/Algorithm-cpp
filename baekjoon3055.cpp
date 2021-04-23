#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char arr[51][51];
int r, c, startx, starty, targetx, targety;
int check[51][51], record[51][51], xmove[4] = { 1, -1, 0, 0 }, ymove[4] = { 0,0,1,-1 };
queue<pair< int, int>> q, v;

void BFS(int x, int y) {
	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty()) {

		int qsize = q.size();
		for (int cnt = 0; cnt < qsize; cnt++) {

			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == targetx && y == targety)
				return;

			if (arr[x][y] != '*') {
				for (int i = 0; i < 4; i++) {
					int nx = x + xmove[i];
					int ny = y + ymove[i];
					if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
						if (!check[nx][ny] && (arr[nx][ny] == '.' || arr[nx][ny] == 'D')) {
							check[nx][ny] = true;
							record[nx][ny] = record[x][y] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}


		int vsize = v.size();
		for (int cnt = 0; cnt < vsize; cnt++) {
			int wx = v.front().first;
			int wy = v.front().second;
			v.pop();

			for (int i = 0; i < 4; i++) {
				int nwx = wx + xmove[i];
				int nwy = wy + ymove[i];
				if (nwx >= 0 && nwx < r && nwy >= 0 && nwy < c) {
					if (arr[nwx][nwy] == '.') {
						arr[nwx][nwy] = '*';
						v.push(make_pair(nwx, nwy));
					}
				}
			}
		}
	}
}


int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				startx = i;
				starty = j;
			}
			if (arr[i][j] == 'D') {
				targetx = i;
				targety = j;
			}
			if (arr[i][j] == '*')
				v.push(make_pair(i, j));
		}
	}

	BFS(startx, starty);

	if (record[targetx][targety] != 0) {
		cout << record[targetx][targety];
	}
	else {
		cout << "KAKTUS";
	}
}