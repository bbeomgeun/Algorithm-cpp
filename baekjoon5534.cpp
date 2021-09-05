#include <iostream>

using namespace std;

int n, answer;
string target, input;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> target;
	for (int i = 0; i < n; i++) {
		cin >> input;
		bool flag = false;
		for (int j = 0; j < input.size(); j++) {
			if (input[j] == target[0]) {
				for (int dif = 1; dif < input.size(); dif++) {
					int cnt = 1;
					int index = j + dif;
					for(int k = 1 ; k < target.size() ; k++){
						if (index >= input.size()) {
							break;
						}
						if (target[k] == input[index]) {
							cnt++;
							index += dif;
						}
						else {
							break;
						}
						if (cnt == target.size()) {
							flag = true;
							break;
						}
					}
					if (flag)	break;
				}
			}
			if (flag) {
				answer++;
				break;
			}
		}
	}
	cout << answer;
}