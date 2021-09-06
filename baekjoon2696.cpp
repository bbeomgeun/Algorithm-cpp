#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

ll T, n, num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		vector<ll> answer;
		priority_queue<ll, vector<ll>, greater<ll>> down;
		priority_queue<ll> up;
		for (int i = 1; i <= n; i++) {
			cin >> num;
			if (i % 2 != 0) {
				up.push(num);
				if (!up.empty() && !down.empty()) {
					if (up.top() > down.top()) {
						int upTemp = up.top();
						int downTemp = down.top();
						up.pop();
						down.pop();
						up.push(downTemp);
						down.push(upTemp);
					}
				}
			}
			else {
				down.push(num);
			}
			if (i % 2 != 0) {
				answer.push_back(up.top());
			}
		}
		cout << answer.size()<<"\n";
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
}