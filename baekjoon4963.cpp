#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int w, h, input, xMove[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, yMove[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, map[50][50], result;
vector<int> v;
queue<pair<int, int>> q;
bool check[50][50];

void BFS(int startX, int startY) {
	result += 1;
	q.push(make_pair(startX, startY));
	check[startX][startY] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int tempX = x + xMove[i];
			int tempY = y + yMove[i];

			if (tempX >= 0 && tempY >= 0 && !check[tempX][tempY] && tempX < h && tempY < w && map[tempX][tempY] == 1) {
				check[tempX][tempY] = true;
				q.push(make_pair(tempX, tempY));
			}
		}
	}
}

int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		else {
			for (int height = 0; height < h; height++) {
				for (int width = 0; width < w; width++) {
					cin >> input;
					map[height][width] = input;
				}
			}
			for (int height = 0; height < h; height++) {
				for (int width = 0; width < w; width++) {
					if (map[height][width] == 1 && !check[height][width]){
							BFS(height, width);
						}
				}
			}
			v.push_back(result);
			result = 0;

			for (int height = 0; height < h; height++) {
				for (int width = 0; width < w; width++) {
					map[height][width] = 0;
					check[height][width] = 0;
				}
			}
		}
	}
	int len = v.size();
	for (int i = 0; i < len; i++) {
		cout << v[i] << endl;
	}
}