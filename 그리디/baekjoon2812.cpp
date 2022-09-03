#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int n, k;
string s;
stack<int> st;

int main() {
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int t = s[i] - '0';
	
		if (k != 0) {
			while (!st.empty() && st.top() < t) {
					st.pop();
					k--;
					if (k == 0)
						break;
			}
		}
		st.push(t);
	}

	string answer = "";
	while (!st.empty()) {
		if (k == 0)
			answer += st.top() + '0';
		else
			k--;
		st.pop();
	}
	
	reverse(answer.begin(), answer.end());
	cout << answer;	
}