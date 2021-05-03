#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int N, num, answer;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		int n = a + b;
		answer += n;
		pq.push(n);
	}

	cout << answer;
}