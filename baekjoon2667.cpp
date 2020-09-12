#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, com[26][26], disX[4] = { 1, -1, 0, 0 }, disY[4] = { 0, 0, 1, -1 }, cnt, homeCount;
bool check[26][26];
queue<pair<int,int>> q;
string s;
vector<int> v;

int bfs(int startX, int startY) {
	q.push(make_pair(startX, startY));
	check[startX][startY] = true;

	while (!q.empty()) {
		int X = q.front().first;
		int Y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tempX = X + disX[i];
			int tempY = Y + disY[i];

			if (com[tempX][tempY] == 1 && !check[tempX][tempY] && tempX >= 0 && tempY >= 0 && tempX < N && tempY < N) {
				cnt += 1;
				check[tempX][tempY] = true;
				q.push(make_pair(tempX, tempY));
			}
		}
	}
	return cnt;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			com[i][j] = s[j]-48;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (com[i][j] == 1 && !check[i][j]) {
				cnt = 1;
				homeCount++;
				v.push_back(bfs(i, j));
			}
		}
	}
	sort(v.begin(),v.end());
	cout << homeCount << endl;
	for (int i = 0; i <homeCount; i++) {
		cout << v[i]<<endl;
	}
}