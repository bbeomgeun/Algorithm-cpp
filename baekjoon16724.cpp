#include<iostream>

using namespace std;

typedef pair<int, int> pii;
int N, M, answer;
string s;
char direction[1001][1001];
int record[1001][1001];

void DFS(int x, int y) { // 나의 경우 DFS를 하되, 방문 두 번 하면 종료시켜주었다.
	if (record[x][y] == 1)
		return;

	if (record[x][y] == 0) {
		answer++;
		record[x][y] = 1;
		return;
	}
	if (record[x][y] == -1) {
		record[x][y] = 0;
	}

	int nx = x;
	int ny = y;

	if (direction[x][y] == 'D') {
		nx += 1;
	}
	else if (direction[x][y] == 'U') {
		nx -= 1;
	}
	else if (direction[x][y] == 'R') {
		ny += 1;
	}
	else if (direction[x][y] == 'L') {
		ny -= 1;
	}

	DFS(nx, ny);
	record[x][y] = record[nx][ny];
}
//기본 아이디어 : DFS를 하면서 갈 수 있는 방향으로 방문을 하되, 사이클이 생기는 구간이 save zone이라 생각
//사이클이 생긴다는 것은 방문했던 곳을 한번 더 방문하면 사이클이고, 그런 순간은 정답으로 간주
// 그 경우가 아니라, 방문을 했는데 애초에 사이클이 생겼던 장소이면 dfs를 호출한 위치 또한 사이클에 포함되므로 종료
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			record[i][j] = -1;
			direction[i][j] = s[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
				DFS(i, j);
		}
	}

	cout << answer;
}