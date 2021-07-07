#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, cnt_k, height[51][51], xmove[8] = { 1, -1, 0, 0, 1, 1, -1, -1 }, ymove[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
char village[51][51];
string s;
pii P;
vector<int> hhh;

int bfs(int low, int high) {
	int temp_k = 0;
	queue<pii> q;
	if (height[P.first][P.second] < low || height[P.first][P.second] > high) // 탐색 전 시작포인트가 범위 안에 있는지 확인
		return temp_k;
	int check[51][51] = {0, };
	check[P.first][P.second] = true; // 우체국에서 시작
	q.push(P);

	while (!q.empty() ) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + xmove[i];
			int ny = y + ymove[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (height[nx][ny] >= low && height[nx][ny] <= high && !check[nx][ny]) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					if (village[nx][ny] == 'K')
						temp_k++;
					if (temp_k == cnt_k)
						return temp_k;
				}
			}
		}
	}
	return temp_k;
} // 여부 리턴 or 방문한 집 갯수 리턴

// 하고 싶은 것
// 낮은 높이, 높은 높이를 임의로 정해서 모든 집에 배달이 되는지 여부를 체크
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			village[i][j] = s[j];
			if (village[i][j] == 'P') {
				P = make_pair(i, j);
			}
			else if (village[i][j] == 'K') {
				cnt_k++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height[i][j];
			hhh.push_back(height[i][j]);
		}
	}

	sort(hhh.begin(), hhh.end());
	int answer = hhh.back() - hhh.front();

	for (int low = 0, high = 0; low < hhh.size() && high < hhh.size() && low<=high; ) { // low, high는 hhh vector용 index
		if (bfs(hhh[low], hhh[high]) == cnt_k) {
			int tmp = hhh[high] - hhh[low];
			if (tmp < answer) {
				answer = tmp;
			}
			low++;
		}
		else
			high++;
	}
	cout << answer;
	// low, high 모든 경우를 탐색하면 시간이 오래 걸릴텐데...
	// 1. 이분 탐색을 이용 -> hint : 특정 low에 대해서 되는 low + 'a' 를 찾아보기
	// 2. 투포인터를 이용 -> hint : 특정 시점에서 low-high를 만족했을 때 다음 스텝은?
	// -> O(N^3)이다. BFS(n^2) * 투포인터(n)
}