#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, pr;

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		ios::sync_with_stdio(false);
		cin.tie(0);
		cin >> N >> M;
		vector<int> v;
		vector<int> answer;
		queue<int> q;
		for (int i = 0; i < N; i++) {
			cin >> pr;
			v.push_back(pr);
			q.push(i);
		}

		while (!q.empty()) {
			int idx = q.front();
			q.pop();

			if (v[idx] != *max_element(v.begin(), v.end())) {
				q.push(idx);
			}
			else {
				answer.push_back(idx);
				v[idx] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			if (answer[i] == M)
				cout << i + 1 << "\n";
		}


	}

}