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
		board[row][col] = -1; // 사과
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
		t++; // 매초 증가
		// 머리 이동
		int nx = snake.front().first + moveTo[d][0];
		int ny = snake.front().second + moveTo[d][1];

		if (nx > N || ny > N || nx < 1 || ny < 1) { // 벽에 부딪치는 경우
			cout << t;
			break;
		}
		if (check[nx][ny]) { // 내 몸에 부딪치는 경우
			cout << t;
			break;
		}
		check[nx][ny] = true;
		snake.push_front({ nx,ny });

		if (board[nx][ny] == -1) { // 사과 발견
			board[nx][ny] = 0; // 먹고 지워주기
		}
		else { // 사과 없으면 꼬리 줄이기
			check[snake.back().first][snake.back().second] = false;
			snake.pop_back();
		}

		if (!command.empty()) {
			if (t == command.front().first) { // t초가 끝난 뒤에 회전하는 명령
				if (command.front().second == 'L') { // 왼쪽
					d = (d + 3) % 4;
				}
				else { // 오른쪽
					d = (d + 1) % 4;
				}
				command.pop_front();
			}
		}
	}
}