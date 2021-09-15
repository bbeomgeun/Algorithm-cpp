#include <iostream>
#include  <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, target, num[10];
char buffer[10], expression[3] = { '+', ' ',  '-' };
vector<string> answer;

void backTracking(int target, int depth) {
	if (depth == target-1) {
		int sum = 0;
		int temp = 1;
		vector<int> result;
		for (int i = 0; i < depth; i++) {
			if (buffer[i] == ' ') {
				if (temp >= 0)
					temp = temp * 10 + num[i + 1];
				else
					temp = temp * 10 - num[i + 1];
			}
			else if (buffer[i] == '+') {
				result.push_back(temp);
				temp =  num[i + 1];
			}
			else if (buffer[i] == '-') {
				result.push_back(temp);
				temp = -num[i + 1];
			}	
		}
		if(temp != 0)
			result.push_back(temp);
		for (auto k : result)
			sum += k;
		if (sum == 0) {
			string temp = "";
			for (int i = 0; i < depth; i++) {
				temp += to_string(num[i]);
				temp += buffer[i];
			}
			temp += to_string(num[depth]);
			answer.push_back(temp);
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		buffer[depth] = expression[i];
		backTracking(target, depth + 1);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> target;
		for (int j = 0; j < target; j++) {
			num[j] = j + 1;
		}
		backTracking(target, 0);
		for (int i = 0; i < target; i++)
			buffer[i] == ' ';
		sort(answer.begin(), answer.end());
		for (auto k : answer)
			cout << k << "\n";
		answer.clear();
	}
	
}