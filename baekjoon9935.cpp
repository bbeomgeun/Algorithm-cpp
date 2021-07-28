#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s, bomb;
stack<char> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s>>bomb;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == bomb.back()) {
			string temp  = "";
			temp += s[i];
			int cnt = 0;
			while (!st.empty()) {
				if (cnt == bomb.size() - 1)
					break;
				temp = st.top() + temp;
				st.pop();
				cnt++;
			}
			if (temp == bomb)
				continue;
			else {
				for (auto c : temp) {
					st.push(c);
				}
			}
		}
		else {
			st.push(s[i]);
		}
	}
	if (st.empty())
		cout << "FRULA";
	else {
		string answer = "";
		while (!st.empty()) {
			answer += st.top();
			st.pop();
		}
		for (int i = answer.size() - 1; i >= 0; i--)
			cout << answer[i];
	} // answer = st.top() + answer 할 경우 메모리 복사가 일어나면서 시간초과가 발생한다.
}