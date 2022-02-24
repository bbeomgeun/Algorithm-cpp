#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> pipi;

int n, num, like, moving[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }, place[21][21], answer;
vector<int> likes[401], order;
vector<pair<int, pii>> result;

bool compare(pipi& a, pipi& b) {
	if (a.first.first == b.first.first) {
		if (a.first.second == b.first.second) {
			if (a.second.first == b.second.first) {
				return a.second.second < b.second.second;
			}
			else {
				return a.second.first < b.second.first;
			}
		}
		else {
			return a.first.second > b.first.second;
		}
	}
	else {
		return a.first.first > b.first.first;
	}
}

pii searchLike(int x, int y, int cur) {
	int result = 0;
	int none = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + moving[i][0];
		int ny = y + moving[i][1];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (place[nx][ny] == 0) { // 빈 칸
				none++;
				continue;
			}
			for (int j = 0; j < likes[cur].size(); j++) { // 비어있진 않으므로 비교
				if (place[nx][ny] == likes[cur][j]) {
					result++;
					break; // 한 방향엔 한 개만 찾으면 끝
				}
			}
		}
	}
	return { result, none };
}

pii searchPlace(int num) {
	vector<pipi> result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (place[i][j] == 0) {
				result.push_back({ searchLike(i, j, num), {i, j} });
			}
		}
	} // 모든 곳 다 탐색
	sort(result.begin(), result.end(), compare);
	return result.front().second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n*n; i++) {
		cin >> num;
		order.push_back(num);
		for (int i = 0; i < 4; i++) {
			cin >> like;
			likes[num].push_back(like);
		}
	}


	for (int i = 0; i < order.size(); i++) {
		pii k = searchPlace(order[i]);
		place[k.first][k.second] = order[i];
		result.push_back({ order[i], {k.first, k.second} });
	}

	for (int i = 0; i < result.size(); i++) {
		int cur = result[i].first;
		int x = result[i].second.first;
		int y = result[i].second.second;
		int cnt = searchLike(x, y, cur).first;

		if (cnt == 1) answer += 1;
		else if (cnt == 2) answer += 10;
		else if (cnt == 3) answer += 100;
		else if (cnt == 4) answer += 1000;
	}

	cout << answer;
}