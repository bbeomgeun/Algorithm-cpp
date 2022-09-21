#include <iostream>
#include <algorithm>

using namespace std;

int N, M, xmove[4] = { 1, -1, 0, 0 }, ymove[4] = { 0,0,1,-1 }, record[51][51];
char arr[51][51];
string s;
int limit, answer;

void DFS(int startX, int startY, int cnt) {
	if (answer < cnt)
		answer = cnt;
	if (answer > limit) {
		return;
	}
	if (startX < 0 || startX >= N || startY < 0 || startY >= M || arr[startX][startY] == 'H')
		return;
	if (record[startX][startY] >= cnt)
		return;
	record[startX][startY] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = startX + (arr[startX][startY] - '0') * xmove[i];
		int ny = startY + (arr[startX][startY] - '0') * ymove[i];
		DFS(nx, ny, cnt + 1);
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	limit = N * M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j];
			record[i][j] = -1;
		}
	}

	DFS(0,0,0);
	if (answer > limit)
		answer = -1;
	cout << answer;
}