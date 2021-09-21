#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int board[101][101], check[101][101], moveTo[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int N, K, L, row, col, t;
char direction;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
deque<pii> snake;
deque<pic> command;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int k = 0; k < K; k++) {
		cin >> row >> col;
		board[row][col] = -1; // ���
	}
	cin >> L;
	for (int l = 0; l < L; l++) {
		cin >> t >> direction;
		command.push_back({ t, direction });
	}

	int x = 1, y = 1, d = 0, t = 0;
	snake.push_back({ x,y });
	check[x][y] = true;
	while (!snake.empty()) {
		t++; // ���� ����
		// �Ӹ� �̵�
		int nx = snake.front().first + moveTo[d][0];
		int ny = snake.front().second + moveTo[d][1];

		if (nx > N || ny > N || nx < 1 || ny < 1) { // ���� �ε�ġ�� ���
			cout << t;
			break;
		}
		if (check[nx][ny]) { // �� ���� �ε�ġ�� ���
			cout << t;
			break;
		}
		check[nx][ny] = true;
		snake.push_front({ nx,ny });

		if (board[nx][ny] == -1) { // ��� �߰�
			board[nx][ny] = 0; // �԰� �����ֱ�
		}
		else { // ��� ������ ���� ���̱�
			check[snake.back().first][snake.back().second] = false;
			snake.pop_back();
		}

		if (!command.empty()) {
			if (t == command.front().first) { // t�ʰ� ���� �ڿ� ȸ���ϴ� ���
				if (command.front().second == 'L') { // ����
					d = (d + 3) % 4;
				}
				else { // ������
					d = (d + 1) % 4;
				}
				command.pop_front();
			}
		}
	}
}