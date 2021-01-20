#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001], N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
		for (int k = 1; k * k <= i; k++) {
			arr[i] = min(arr[i], arr[i - k * k] + 1);
		}
	}
	cout << arr[N];
}