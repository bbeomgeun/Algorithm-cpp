#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int n, m, arr[9][9], visit[9][9], answer = 100, cctv, direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }, combinationList[9];
vector<pii> cctvList;
;

int getVisitCnt() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && arr[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = 0;
		}
	}
}

void move(int x, int y, int cctvNum, int dir) {
	while (x < n && y < m && x >= 0 && y >= 0) {
		if (arr[x][y] == 6) { // 벽
			break;
		}
		else if (arr[x][y] == 0) { // 갈 수 있는 곳
			visit[x][y] = 1;
		} // 그 외 cctv 구역
		x += direction[dir][0];
		y += direction[dir][1];
	}
}

void search(int x, int y, int cctvNum, int dir) {
	if (cctvNum == 1) {
		move(x, y, cctvNum, dir);
	}
	else if (cctvNum == 2) {
		move(x, y, cctvNum, dir);
		move(x, y, cctvNum, (dir+2)%4);
	}
	else if (cctvNum == 3) {
		move(x, y, cctvNum, dir);
		move(x, y, cctvNum, (dir+3)%4);
	}
	else if (cctvNum == 4) {
		move(x, y, cctvNum, dir);
		move(x, y, cctvNum, (dir + 2) % 4);
		move(x, y, cctvNum, (dir + 3) % 4);
	}
	else if (cctvNum == 5) {
		move(x, y, cctvNum, dir);
		move(x, y, cctvNum, (dir + 1) % 4);
		move(x, y, cctvNum, (dir + 2) % 4);
		move(x, y, cctvNum, (dir + 3) % 4);
	}
}

void combination(int depth, int n) {
	if (depth == n) {
		for (int i = 0; i < cctv; i++) {
			int x = cctvList[i].first;
			int y = cctvList[i].second;
			search(x, y, arr[x][y], combinationList[i]);
		}
		answer = min(answer, getVisitCnt());
		clear();
		return;
	}
	for (int i = 0; i < 4; i++) {
		combinationList[depth] = i;
		combination(depth + 1, n);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cctvList.push_back({ i, j });
				cctv++;
			}
		}
	}

	combination(0, cctv);
	cout << answer;
}