#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N, X;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X;
		if (X == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << "\n";
				pq.pop();
			}
			else
				cout << 0 << "\n";
		}
		else {
			pq.push({abs(X), X});
		}
	}
	return 0;
}