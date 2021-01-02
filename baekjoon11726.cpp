#include <iostream>

using namespace std;

int n;
int tile[1001];

int dp(int n) {
	if (n < 2)
		return 1;
	if (tile[n] != 0)
		return tile[n] % 10007;
	else
		return (tile[n] =  dp(n - 1) % 10007 + dp(n - 2) % 10007) % 10007;
}


int main() {
	cin >> n;

	cout << dp(n);

}