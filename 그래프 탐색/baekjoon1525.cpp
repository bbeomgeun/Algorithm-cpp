#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#define INF 987654321

using namespace std;

int n, answer = INF, moving[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
string input, target = "123456780";
typedef pair<string, int> psi;
unordered_set<string> visit;

// BFS Ž���� ���ڿ��� �Ѵ�
// ���ڿ����� 0�� �ű�鼭 ���� �� �ִ� ���ڿ�(����)��� ���� �׷����� ���� ���ڿ����� bfsŽ���Ѵٰ� �����ϸ� �ȴ�.

void BFS(string start) {
	queue<psi> q;
	q.push({ start, 0 });
	visit.insert(start);

	while (!q.empty()) {
		string curMap = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (curMap == target) {
			answer = cnt;
			return;
		}

		int cur = curMap.find('0');
		int x = cur / 3;
		int y = cur % 3;

		for (int i = 0; i < 4; i++) {
			int nx = x + moving[i][0];
			int ny = y + moving[i][1];

			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string next = curMap;
				int nextIndex = nx * 3 + ny;
				swap(next[cur], next[nextIndex]);
				if (visit.find(next) == visit.end()) {
					visit.insert(next);
					q.push({ next, cnt + 1 });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> n;
			input += n + '0';
		}
	}

	BFS(input);

	if (answer == INF)
		cout << -1;
	else
		cout << answer;
}