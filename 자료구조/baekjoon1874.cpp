#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack <int> s;
vector <string> result;
int input[100001];
int n, cnt =1 ;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	for (int i = 1; i <= n; i++) {
		s.push(i);
		result.push_back("+");
		while (!s.empty() && ( input[cnt] == s.top())) {
			s.pop();
			result.push_back("-");
			cnt++;
		}
	}

	if (!s.empty()) {
		cout << "NO" << "\n";
	}
	else {
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << "\n";
	}
}