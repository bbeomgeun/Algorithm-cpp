#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int K, input, result;

int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> input;
		if (input == 0) {
			s.pop();
		}
		else {
			s.push(input);
		}
	}
	int size = s.size();
	for (int i = 0; i < size; i++) {
		int temp = s.top();
		result += temp;
		s.pop();
	}

	cout << result;
}
