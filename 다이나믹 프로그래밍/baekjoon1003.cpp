#include <iostream>

using namespace std;

int T, input;
int arr[41] = { 0, 1, 1, };

int main() {
	for (int i = 3; i <= 40; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> input;
		if (input == 0) {
			cout << 1 << " " << 0 << "\n";
		}
		else
			cout << arr[input - 1] <<" "<< arr[input] <<"\n";
	}
	return 0;
}