#include <iostream>
using namespace std;

int Qarray[10001], N, input;
string s;

class array_Queue {
public:
	int n;
	int start;
	int end;

	array_Queue() {
		start = 0;
		n = 0;
		end = 0;
	}

	bool empty() {
		return n == 0;
	}
	
	void push(int X) {
		Qarray[end] = X;
		n++;
		end++;
	}

	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			int temp = Qarray[start];
			start++;
			n--;
			return temp;
		}
	}

	int front() {
		if (empty())
			return -1;
		else
			return Qarray[start];
	}

	int back() {
		if (empty())
			return -1;
		else
			return Qarray[end-1];
	}

	int size() {
		return n;
	}
};

int main() {
	cin >> N;
	array_Queue aq;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push") {
			cin >> input;
			aq.push(input);
		}
		else if (s == "front") 
			cout << aq.front() << "\n";
		else if (s == "back")
			cout << aq.back() << "\n";
		else if (s == "empty")
			cout << aq.empty() << "\n";
		else if (s == "size")
			cout << aq.size() << "\n";
		else if (s == "pop")
			cout << aq.pop() << "\n";
	}


	return 0;
}