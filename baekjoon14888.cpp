#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000
#define MIN -1000000000

using namespace std;

int n, x, maxA = MIN, minA = MAX;
vector<int> numList, opList, operation;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		numList.push_back(x);
	}

	for (int i = 0; i < 4; i++) {
		cin >> x;
		opList.push_back(x);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < opList[i]; j++) {
			operation.push_back(i);
		}
	} // 연산자 개수대로 펼치기

	do {
		int temp = numList[0];
		for (int i = 0; i < operation.size(); i++) {
			if (operation[i] == 0) {
				temp += numList[i + 1];
			}
			else if (operation[i] == 1) {
				temp -= numList[i + 1];
			}
			else if (operation[i] == 2) {
				temp *= numList[i + 1];
			}
			else {
				temp /= numList[i + 1];
			}
		}
		maxA = max(temp, maxA);
		minA = min(temp, minA);
		
	} while (next_permutation(operation.begin(), operation.end()));

	cout << maxA << "\n" << minA;
}