#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

int T, N;
string s, command;
deque<int> dq;

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> command>>N>>s;
		string cut = s.substr(1, s.size() - 2);
		istringstream ss(cut);
		string buffer = "";

		while (getline(ss, buffer, ',')) {
			dq.push_back(stoi(buffer));
		}
		int reverseFlag = false;
		int endFlag = false;
		for (auto k : command) {
			if (k == 'R') {
				reverseFlag = !reverseFlag;
			}
			else if (k == 'D') {
				if (reverseFlag) {
					if (dq.size() > 0)
						dq.pop_back();
					else {
						endFlag = true;
						cout << "error" << "\n";
						break;
					}
				}
				else {
					if (dq.size() > 0)
						dq.pop_front();
					else {
						endFlag = true;
						cout << "error" << "\n";
						break;
					}
				}
			}
		}
		if (endFlag)
			continue;
		else {
			string answer = "";
			answer += '[';
			if (!reverseFlag) {
				while (!dq.empty()) {
					answer += to_string(dq.front());
					answer += ',';
					dq.pop_front();
				}
			}
			else {
				while (!dq.empty()) {
					answer += to_string(dq.back());
					answer += ',';
					dq.pop_back();
				}
			}
			if (answer.size() > 1)
				answer[answer.size() - 1] = ']';
			else if (answer.size() == 1)
				answer += ']';
			cout << answer<<"\n";
		}
	}
}