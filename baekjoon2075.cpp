#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
// greater -> 오름차순 = 최소힙
int N, num;

// 메모리 제한이 4MB이다. 따라서 모든 수를 입력받아 정렬하는 방식은 메모리 초과가 날 것이고
// 우선순위큐를 이용하여 NlogN으로 입력받고 n개 이외의 수는 pop하는 방식으로 진행한다.
// pq에는 항상 N개의 수만 저장되어 있고 모든 수를 거치고 나면 최소힙의 front가 n번째 큰 수가 된다.
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			pq.push(num);
		}
		while (pq.size() != N) {
			pq.pop();
		}
	}
	cout << pq.top();
}
