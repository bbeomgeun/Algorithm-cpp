#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int N, n;
string s;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s == "push_back") {
			cin >> n;
			dq.push_back(n);
		}
		else if (s == "push_front") {
			cin >> n;
			dq.push_front(n);
		}
		else if (s == "front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		else if (s == "back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
		else if (s == "empty") {
			cout << dq.empty() << "\n";
		}
		else if (s == "pop_front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size()<<"\n";
		}
	}
}