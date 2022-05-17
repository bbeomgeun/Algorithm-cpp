#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1000001

using namespace std;

typedef pair<int, int> pii;

int n, need, deadLine;
priority_queue<pii, vector<pii>, less<pii>> pq;
int answer = MAX;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> need >> deadLine;
		pq.push({deadLine, need });
	}

	while (!pq.empty()) {
		int finishTime = pq.top().first;
		int spendTime = pq.top().second;
		pq.pop();

		finishTime = min(finishTime, answer);

		answer = finishTime - spendTime;
	}

	if (answer < 0) {
		cout << -1;
	}
	else
		cout << answer;
}