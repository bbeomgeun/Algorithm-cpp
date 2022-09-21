#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, K, M, V, C;
priority_queue<int, vector<int>, greater<int>> bag;
priority_queue<pii, vector<pii>, greater<pii>> jam;
priority_queue<int> temp;
//가방, 보석 오름차순 정렬
// 가방을 크기순으로 보면서 현재 크기에 넣을 수 있는 가장 적합한 보석을 넣기

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> M >> V; // 무게, 가치
		jam.push(make_pair(M, V));
	}
	for (int i = 0; i < K; i++) {
		cin >> C;
		bag.push(C);
	}

	long long answer = 0;

	while (!bag.empty()) { // 가방을 모두 사용할때까지
		int limit = bag.top();
		while (!jam.empty() && jam.top().first <= limit) { //가방에 넣을 수 있는 것들을 
			temp.push(jam.top().second); // 가능한 무게 중 가치 순으로
			jam.pop();
		}
		if (!temp.empty()) { // 가방에 넣을 보석이 없는 경우 가방 사용 x
			answer += temp.top(); // 가치 가장 높은 것 pick
			temp.pop();
		}
		bag.pop();
	}
	cout << answer;
	return 0;
}