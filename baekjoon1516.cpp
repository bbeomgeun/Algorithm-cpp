#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, t, need, timer[501], result[501], inDegree[501];
vector<int> v[501], start;
queue<int> q;

void topologicalSort() {
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		int now = q.front();
		q.pop();
		result[now] += timer[now]; // 여기서 이제까지 갱신된 최대비용 + 자신 건물 짓는 비용
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (result[next] != 0) {
				result[next] = max(result[next], result[now]); // 다음 노드들은 앞에 연결된 노드들 중 최대 비용으로 갱신
			}
			else
				result[next]  = result[now];

			inDegree[next]--;
			if (inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t;
		timer[i] = t;
		while (1) {
			cin >> need;
			if (need == -1)
				break;
			v[need].push_back(i);
			inDegree[i]++;
		}
	}

	topologicalSort();

	for (int i = 1; i <= N; i++)
		cout << result[i] << "\n";
}