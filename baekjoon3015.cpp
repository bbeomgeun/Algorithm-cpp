#include <iostream>
#include <stack>

using namespace std;

int n, arr[500001];
long long answer;
stack<pair<int, int>> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// ������ ���������ǰԲ� ���������(top�� ���� �۰�)

	for (int i = 0; i < n; i++) {
		int cnt = 1;
		int num = arr[i];
		while (!st.empty() && st.top().first <= num) {
			if (st.top().first == num) {
				answer += st.top().second;
				cnt = st.top().second + 1;
				st.pop();
			}
			else {
				answer += st.top().second;
				st.pop();
				//cnt = 1;
			}
		}

		if (!st.empty()) {  // �ٷ� �پ��ִ� ���
			answer++;
		}
		st.push(make_pair(num, cnt));
	}
	cout << answer;
}