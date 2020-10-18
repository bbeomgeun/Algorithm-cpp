#include <iostream>
#include <stack>
#include <string>
using namespace std;

string input;
stack<char> s;

int main() {
	while (true) {
		getline(cin, input);
		if (input == ".")
			break;
		else {
			for (int i = 0; i < input.size(); i++) {
				if (input[i] == '(' || input[i] == '[') {
					s.push(input[i]);
				}
				else if (input[i] == ')' || input[i] == ']') {
					if (s.empty()) {
						s.push(input[i]);
						break;
					}
					else {
						if (input[i] == ')') {
							if (s.top() == '(')
								s.pop();
							else {
								break;
							}
						}
						else if (input[i] == ']'){
							if (s.top() == '[')
								s.pop();
							else {
								break;
							}
						}
					}
				}
			}
			if(s.empty())
				cout << "yes" << "\n";
			else {
				cout << "no" << "\n";
				while (!s.empty())
					s.pop();
			}
		}
	}
}