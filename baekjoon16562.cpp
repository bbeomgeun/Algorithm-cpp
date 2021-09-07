#include <iostream>

using namespace std;

int N, M, K, a, b; // 학생수 친구관계수 갖고있는 돈
int cost[10001], parent[10001];

int getParent(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a > b) {
		parent[a] = b;
	}
	else
		parent[a] = b;

	if (cost[a] > cost[b]) {
		cost[a] = cost[b];
	}
	else
		cost[b] = cost[a];
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		unionParent(a, b);
	}
	int answer = 0;

	for (int i = 1; i <= N; i++) {
		if (parent[i] == i) {
			answer += cost[i];
		}
	}

	if (K - answer >= 0)
		cout << answer;
	else
		cout << "Oh no";
}