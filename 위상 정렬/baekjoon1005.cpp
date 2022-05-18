#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, M, X, Y, target;
int buildTime[1001], inorder[1001], timeSum[1001];
vector<int> v[1001];
queue<int> q;

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (inorder[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front();
			q.pop();
			timeSum[x] += buildTime[x];
			for (int j = 0; j < v[x].size(); j++) {
				int nx = v[x][j];
				if (timeSum[nx] == 0) {
					timeSum[nx] = timeSum[x];
				}
				else {
					timeSum[nx] = max(timeSum[nx], timeSum[x]);
				}
				inorder[nx]--;
				if (inorder[nx] == 0) {
					q.push(nx);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int n = 1; n <= N; n++) {
			cin >> buildTime[n];
		}
		for (int m = 0; m < M; m++) {
			cin >> X >> Y;
			v[X].push_back(Y);
			inorder[Y]++;
		}
		cin >> target;
		//topologySort하면서 모든 노드에 시간을 갱신해준다.
		//처음 방문 시 이제까지 누적 시간, 이미 방문했다면 최대 시간으로 갱신

		topologySort();
		
		cout << timeSum[target] << "\n";

		for (int i = 0; i <= N; i++) {
			v[i].clear();
			buildTime[i] = 0;
			timeSum[i] = 0;
		}
	}
}