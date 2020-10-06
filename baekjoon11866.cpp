#include <iostream>
#include <queue>

using namespace std;

queue <int> q;
int N, K;
vector<int> v;
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();

		if (!q.empty()) {
			cout << ", ";
		}
		
	}
	cout << ">" << endl;
	return 0;
}