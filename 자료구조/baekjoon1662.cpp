#include <iostream>
#include <string>

using namespace std;

string s;
int i = 0;

int DFS(string s, int x) {
	int answer = 0;
	for (i = x; i < s.size(); i++) {
		if (s[i] == '(') {
			answer--;
			int count = s[i-1]-'0';
			int temp = DFS(s, i+1);
			answer += temp * count;
		}
		else if (s[i] == ')') {
			return answer;
		}
		else {
			answer++;
		}
	}
	return answer;
}

int main() {
	cin >> s;
	cout << DFS(s, 0);
}