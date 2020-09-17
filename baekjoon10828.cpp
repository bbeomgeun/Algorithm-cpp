#include <iostream>
using namespace std;

int N, input;
string S;
int arr[10001];

class arr_stack {
public:
	int top_index;
	int  MAX_SIZE;
	// int* arr;

	arr_stack(int size) {
		top_index = -1;
		MAX_SIZE = size;
		//arr = new int[size];
	}

	int empty() {
		if (top_index == -1)
			return 1;
		else
			return 0;
	}
	int size() {
		return top_index + 1;
	}

	void push(int data) {
		/*if (size() == MAX_SIZE) {
			return 0;
		}
		else {
			top_index += 1;
			arr[top_index] = data;
		}*/
		top_index += 1;
		arr[top_index] = data;
	}

	int pop() {
		if (empty())
			return -1;
		else {
			int temp = arr[top_index];
			top_index -= 1;
			return temp;
		}
	}

	int top() {
		if (empty())
			return -1;
		else
			return arr[top_index];
	}
};

int main() {
	arr_stack s(10001);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S;
		if (S == "push") {
			cin >> input;
			s.push(input);
		}
		else if (S == "pop") {
			cout << s.pop() << endl;
		}
		else if (S == "size") {
			cout << s.size() << endl;
		}
		else if (S == "empty") {
			cout << s.empty() << endl;
		}
		else if (S == "top") {
			cout << s.top() << endl;
		}
	}
	return 0;
}