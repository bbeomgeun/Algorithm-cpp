//BFS로 풀면 상하좌우 탐색 순서에 따라서 결과가 달라진다.
//DFS로 풀어서 모든 경우의 수로 탐색을 끝까지 해야한다. & 백트래킹

#include <iostream>
#include <algorithm>
using namespace std;

bool check[21][21];
int R, C, char_check[92], board[21][21], xMove[4] = { 1, -1, 0, 0 }, yMove[4] = { 0, 0, 1, -1 }, result;
string s;

void DFS(int startX, int startY, int num) {
	char_check[board[startX][startY]] = true;
	check[startX][startY] = true;
	num++;

	for (int i = 0; i < 4; i++) {
		int tempX = startX + xMove[i];
		int tempY = startY + yMove[i];
		if (tempX >= 0 && tempX < R && tempY >= 0 && tempY < C && !char_check[board[tempX][tempY]] && !check[tempX][tempY]) {
			DFS(tempX, tempY, num);
		}
	}
	result = max(result, num);
	num--;
	check[startX][startY] = false;
	char_check[board[startX][startY]] = false;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			board[i][j] = s[j];
		}
	}
	DFS(0, 0, 0);
	cout << result;
}