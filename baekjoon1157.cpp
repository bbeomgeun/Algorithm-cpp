#include <iostream>

using namespace std;

string input;
int arr[92], m, idx, cnt;

int main() {
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 97) {
			input[i] -= 32;
			arr[input[i]] += 1;
		}
		else {
			arr[input[i]] += 1;
		}
	}

	for (int i = 65; i < 91; i++) {
		if (arr[i] >= m) {
			idx = i;
			m = arr[i];
		}
	}
	
	for (int i = 65; i < 91; i++) {
		if (m == arr[i])
			cnt += 1;
	}

	if (cnt == 1) {
		cout << char(idx);
	}
	else {
		cout << "?";
	}
}