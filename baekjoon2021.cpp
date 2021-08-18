#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, L, num, start, target;
vector<int> route[100001];
vector<int> station[100001];
bool check[100001];
bool routeCheck[100001];


int BFS(int startX, int endX) {
	queue<int> q;
	check[startX] = true;
	for (auto nextRoute : station[startX]) {
		routeCheck[nextRoute] = true;
		q.push(nextRoute); // 시작점이 포함되어 있는 루트들
	}
	
	int count = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int curRoute = q.front();
			q.pop();

			for (auto nextStation : route[curRoute]) {
				// 왜 return 먼저 안하고 continue하면 결과가 달라질까?
				//0-1BFS
				if (nextStation == endX)
					return count;
				if (check[nextStation])
					continue;
				check[nextStation] = true;
				for (auto nRoute : station[nextStation]) {
					if (routeCheck[nRoute])
						continue;
					q.push(nRoute);
					routeCheck[nRoute] = true;
				}
			}
		}
		count++;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;

	for (int i = 1; i <= L; i++) {
		while (1) {
			cin >> num;
			if (num == -1)
				break;
			route[i].push_back(num); // 루트를 지나는 역
			station[num].push_back(i); // 역에 연결된 루트 저장
		}
	}
	cin >> start >> target;

	//for (int i = 1; i <= N; i++) {
	//	check[i] = -1;
	//}

	cout<<BFS(start, target);
}