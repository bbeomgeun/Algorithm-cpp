#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;

int n, num;

// minpq와 maxpq 두개를 이용해서 가운데 값을 선택한다.
// 항상 top은 minpq의 top이 더 크며 배열 값에서 중간값까지는 maxpq에 넣고 그 외는 minpq에 넣는 메커니즘
// 그러면 정렬된 순서로 입력받은 값중 최솟값 ~ 중간값은 maxpq이므로 이 중에서 중간값이 가장 크므로 maxpq의 top이 된다.
// 그 이후 나머지 중간값+1 ~ 최댓값은 minpq에 들어가있고 만약 minpq의 top이 maxpq보다 더 작으면
// 10 20 40 30 50 에서 40과 30과 같은 경우이므로 둘이 top끼리 바꿔준다.

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (min_pq.size() == max_pq.size()) {
			max_pq.push(num);
		}
		else {
			min_pq.push(num);
		}
		if (!max_pq.empty() && !min_pq.empty() && min_pq.top() < max_pq.top()) {
			int tempValue = min_pq.top();
			min_pq.pop();
			min_pq.push(max_pq.top());
			max_pq.pop();
			max_pq.push(tempValue);
		}
		cout << max_pq.top()<<"\n";

	}
}