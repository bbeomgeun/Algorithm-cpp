#include <iostream>
#include <unordered_set>
using namespace std;

int n, num, shuffle[49], before[49], after[49], target[49], answer[49], cnt;
unordered_set<string> checkSet;

bool isCorrect() {
	for (int i = 0; i < n; i++) {
		if (target[i] != answer[i])
			return false;
	}
	return true;
}

void shuffling() {
	for (int i = 0; i < n; i++) {
		after[shuffle[i]] = before[i];
	}
	for (int i = 0; i < n; i++) {
		before[i] = after[i];
	}
	for (int i = 0; i < n; i++) {
		answer[after[i]] = i % 3;
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		before[i] = i;
		answer[i] = i % 3;
	}
}

bool check() {
	string temp = "";
	for (int i = 0; i < n; i++) {
		temp += answer[i]+'0';
	}
	if (checkSet.find(temp) == checkSet.end()) {
		checkSet.insert(temp);
		return true;
	}
	return false;
}

void print() {
	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";;
	}
	cout << "\n";
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> target[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> shuffle[i];
	}

	init();
	while (!isCorrect()) {
		cnt++;
		shuffling();
		print();
		if (!check()) {
			cnt = -1;
			break;
		}
	}

	cout << cnt;
}