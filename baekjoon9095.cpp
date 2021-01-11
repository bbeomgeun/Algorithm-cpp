#include <iostream>
using namespace std;

int arr[12] = {0, 1, 2, 4, };
int T,n;

int dp(int n) {
	if (n <= 3) {
		return arr[n];
	}
	else{
		if (arr[n]) {
			return arr[n];
		}
		else {
			return arr[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp(n) << "\n";;
	}
}