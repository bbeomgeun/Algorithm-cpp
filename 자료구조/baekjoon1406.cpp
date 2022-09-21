#include <iostream>
#include <stack>

using namespace std;

string s, command;
stack<char> leftStack, rightStack;
char sc;
int n;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		leftStack.push(s[i]);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "L") {
			if (leftStack.size() > 0) {
				rightStack.push(leftStack.top());
				leftStack.pop();
			}
		}
		else if (command == "D") {
			if (rightStack.size() > 0){
				leftStack.push(rightStack.top());
				rightStack.pop();
			}
		}
		else if (command == "B") {
			if(leftStack.size() > 0)
				leftStack.pop();
		}
		else if (command == "P") {
			cin >> sc;
			leftStack.push(sc);
		}
	}

	while (!leftStack.empty()) {
		rightStack.push(leftStack.top());
		leftStack.pop();
	}

	while (!rightStack.empty()) {
		cout << rightStack.top();
		rightStack.pop();
	}
}