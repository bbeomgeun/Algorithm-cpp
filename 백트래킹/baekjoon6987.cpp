#include <iostream>
#include <vector>
#include <string>

using namespace std;

int teamList[16] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int teamList2[16] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };
int num, game[6][3], input[6][3];
vector<int> answer;
bool resolve;

bool isOk() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			if (game[i][j] != input[i][j])
				return false;
		}
	}
	return true;
}

void DFS(int round) {
	if (round == 15) { // 16¶ó¿îµå
		if (isOk()) {
			resolve = true;
		}
		return;
	}

	if (resolve)
		return;

	int t1 = teamList[round];
	int t2 = teamList2[round];

	// ½Â, ÆÐ
	game[t1][0]++;
	game[t2][2]++;
	DFS(round + 1);
	game[t1][0]--;
	game[t2][2]--;
	// ¹«, ¹«
	game[t1][1]++;
	game[t2][1]++;
	DFS(round + 1);
	game[t1][1]--;
	game[t2][1]--;
	// ÆÐ, ½Â
	game[t1][2]++;
	game[t2][0]++;
	DFS(round + 1);
	game[t1][2]--;
	game[t2][0]--;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int T = 0; T < 4; T++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> num;
				input[i][j] = num;
			}
		}

		DFS(0);

		if (resolve) {
			answer.push_back(1);
		}
		else {
			answer.push_back(0);
		}
		resolve = false;
	}

	for (int i = 0; i < 4; i++) {
		cout << answer[i] << " ";
	}
}