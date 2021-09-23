#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define INF 987654321

using namespace std;

int n, buffer[11], m, mx;
string answer;
vector<int> input;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buffer[i];
	}
	cin >> m;

	int firstMin = INF, secondMin = INF;
	int firstIndex, secondIndex;

	for (int i = 0; i < n; ++i) {
		if (buffer[i] < firstMin) {
			firstMin = buffer[i];
			firstIndex = i;
		}
	}

	for (int i = 1; i < n; ++i) {
		if (buffer[i] < secondMin) {
			secondMin = buffer[i];
			secondIndex = i;
		}
	}

	if (secondMin > m) {
		cout << "0";
		return 0;
	}
	answer += to_string(secondIndex);
	int d = (m - secondMin) / firstMin;
	for (int i = 0; i < d; i++) {
		answer += to_string(firstIndex);
	}
	m -= secondMin;
	m = m % firstMin;

	for (int i = 0; i < answer.size(); i++) {
		int index = answer[i] - '0';
		for (int j = n - 1; j >= 0; j--) {
			if (m >= buffer[j] - buffer[index]) { // value
				char temp = j + '0';
				m -= (buffer[j] - buffer[index]);
				answer[i] = temp;
				break;
			}
		}
	}
	cout << answer;
}