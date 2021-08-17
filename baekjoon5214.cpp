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
			tube[m].push_back(num); // 튜브에 연결된 역
			station[num].push_back(m); // 역에 연결된 튜브
		}
	}
	vector<int> visited(N + 1, -1); // station 체크
	vector<int> visitedTube(M + 1, -1); // 튜브 체크
	visited[1] = 1;
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < station[x].size(); i++) { // 1번역에 연결된 튜브
			int nextTube = station[x][i];
			if (visitedTube[nextTube] != -1)
				continue;
			visitedTube[nextTube] = 1;
			for (int j = 0; j < tube[nextTube].size(); j++) { // 튜브에 연결된 역들 체크
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