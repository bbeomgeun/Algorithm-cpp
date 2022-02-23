#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct tree {
	int x;
	int y;
	int age;
};

int N, M, K, x, y, z;
int energy[11][11], farm[11][11], moving[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };
vector<tree> deadTrees;
deque<int> trees[11][11];

void spring() { // 자신의 나이만큼 양분을 먹고, 나이가 1살 늘어남, 여러 나무일경우 나이 어린 순으로, 부족하면 그냥 죽음
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
 			if (trees[i][j].empty())
				continue;
			if (trees[i][j].size() > 1) {
				sort(trees[i][j].begin(), trees[i][j].end());
			}
			int size = trees[i][j].size();
			for (int k = 0; k < size; k++) {
				int age = trees[i][j].front();
				if (age <= farm[i][j]) {
					trees[i][j].push_back(age+ 1);
					trees[i][j].pop_front();
					farm[i][j] -= age;
				}
				else {
					deadTrees.push_back({ i, j,age });
					trees[i][j].pop_front();
				}
			}
		}
	}
}

void summer() {
	for (auto t : deadTrees) {
		farm[t.x][t.y] += t.age / 2;
	}
	deadTrees.clear();
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int age : trees[i][j]) {
				if (age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int nx = i + moving[k][0];
						int ny = j + moving[k][1];
						if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
							trees[nx][ny].push_back(1); // 새 나무
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			farm[i][j] += energy[i][j];
		}
	}
}

int answer() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt += trees[i][j].size();
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> energy[i][j];
			farm[i][j] = 5; // 최초
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		trees[x - 1][y - 1].push_back(z);
		// 최초 나무 x-1, y-1에 z 나이
	}

	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	cout << answer();
}