#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int n, k, answer;

int main() {
	cin >> n>>k;
	if (n == 1000000) {
		cout << n;
		return 0;
	}
	else if (n >= 1 && n <= 10) {
		cout << -1;
		return 0;
	}
	else if (n <= 100 && n % 10 == 0) {
		cout << -1;
		return 0;
	}
	else {
		queue<int> q;
		q.push(n);
		for (int i = 0; i < k; i++) {
			int qsz = q.size();
			unordered_map<int, int> m;
			for (int j = 0; j < qsz; j++) {
				int num = q.front();
				q.pop();
				string temp = to_string(num);
				for (int a = 0; a < temp.size(); a++) {
					for (int b = a + 1; b < temp.size(); b++) {
						temp = to_string(num);
						char tc = temp[a];
						temp[a] = temp[b];
						temp[b] = tc;
						int result = stoi(temp);
						if (m.find(result) == m.end()) {
							q.push(result);
							m[result]++;
						}
					}					
				}
			}
		}
		while (!q.empty()) {
			answer = max(answer, q.front());
			q.pop();
		}
		cout << answer;
		return 0;
	}
}