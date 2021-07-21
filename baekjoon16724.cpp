#include<iostream>

using namespace std;

typedef pair<int, int> pii;
int N, M, answer;
string s;
char direction[1001][1001];
int record[1001][1001];

void DFS(int x, int y) { // ���� ��� DFS�� �ϵ�, �湮 �� �� �ϸ� ��������־���.
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
//�⺻ ���̵�� : DFS�� �ϸ鼭 �� �� �ִ� �������� �湮�� �ϵ�, ����Ŭ�� ����� ������ save zone�̶� ����
//����Ŭ�� ����ٴ� ���� �湮�ߴ� ���� �ѹ� �� �湮�ϸ� ����Ŭ�̰�, �׷� ������ �������� ����
// �� ��찡 �ƴ϶�, �湮�� �ߴµ� ���ʿ� ����Ŭ�� ����� ����̸� dfs�� ȣ���� ��ġ ���� ����Ŭ�� ���ԵǹǷ� ����
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