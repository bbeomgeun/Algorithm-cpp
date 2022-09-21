#include <iostream>
using namespace std;

string S;
char arr[100];

class arr_stack {
public:
	int top_idx;
	int maxSize;

	arr_stack(int size) {
		maxSize = size;
		top_idx = -1;
	}

	void push(char data) {
		top_idx += 1;
		arr[top_idx] = data;
	}

	int empty() {
		if (top_idx == -1)
			return true;
		else
			return false;
	}

	char pop() {
		if (empty())
			return -1;
		else {
			char temp = arr[top_idx];
			top_idx -= 1;
			return temp;
		}
	}

	char top() {
		return arr[top_idx];
	}
};

int isChar(char c) {
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

int isOper(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

int operToNum(char c) {
	if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '(')
		return 0;
}

int comparision(char c1, char c2) {
	int C1 = operToNum(c1);
	int C2 = operToNum(c2);

	if (C1 >= C2)
		return 1;
	else if (C1 < C2)
		return 0;
}

int main() {
	arr_stack st(100);
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (isChar(S[i]))
			cout << S[i];
		else if (S[i] == ')') {
			while (st.top() != '(')
				cout << st.pop();
			st.pop();					// ( ¾ø¾Ö±â
		}
		else if (S[i] == '(')
			st.push(S[i]);

		else if (isOper(S[i])) {
			if (st.empty())
				st.push(S[i]);
			else{
				while (comparision(st.top(), S[i]))
					cout << st.pop();
				st.push(S[i]);
			}
		}
	}
	while (!st.empty())
		cout<<st.pop();

	return 0;
}