#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
int N, K, M, num;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> M;
	vector<vector<int>> tube(M + 1);
	vector<vector<int>> station(N + 1);
	vector<int> endStation;
	for (int m = 1; m <= M; m++) {
		for (int k = 0; k < K; k++) {
			cin >> num;
			tube[m].push_back(num); // Ʃ�꿡 ����� ��
			station[num].push_back(m); // ���� ����� Ʃ��
		}
	}
	vector<int> visited(N + 1, -1); // station üũ
	vector<int> visitedTube(M + 1, -1); // Ʃ�� üũ
	visited[1] = 1;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < station[x].size(); i++) { // 1������ ����� Ʃ��
			int nextTube = station[x][i];
			if (visitedTube[nextTube] != -1)
				continue;
			visitedTube[nextTube] = 1;
			for (int j = 0; j < tube[nextTube].size(); j++) { // Ʃ�꿡 ����� ���� üũ
				int nextStation = tube[nextTube][j];
				if (visited[nextStation] == -1) {
					q.push(nextStation);
					visited[nextStation] = (visited[x] + 1);
					}
				}
			}
		}
	cout << visited[N];
	}