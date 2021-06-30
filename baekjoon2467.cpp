#include <iostream>

using namespace std;

int N, arr[100001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int first = 0;
	int last = N-1;
	int minValue = arr[first] + arr[last];
	int val1 = arr[first];
	int val2 = arr[last];
	while (first < last) {
		if (abs(minValue) > abs(arr[first] + arr[last])) {
			minValue = arr[first] + arr[last];
			val1 = arr[first];
			val2 = arr[last];
		}
		if (arr[first] + arr[last] > 0) {
			last--;
		}
		else if (arr[first] + arr[last] < 0) {
			first++;
		}
		else {
			break;
		}
	}
	cout << val1 << " " << val2;
}