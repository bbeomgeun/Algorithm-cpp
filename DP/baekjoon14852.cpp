#include <iostream>
#define DIV 1000000007

using namespace std;

typedef  long long ll;

ll arr[1000001][2];
int n;

int main() {
	cin >> n;

	arr[0][0] = 1;
	arr[1][0] = 2;
	arr[2][0] = 7;

	for (int i = 3; i <= n; i++) {
		arr[i][1] = (arr[i - 3][0] + arr[i - 1][1]) % DIV;
		arr[i][0] = (arr[i - 1][0] * 2 + arr[i - 2][0] * 3 + 2 * arr[i][1]) % DIV;
	}

	cout << arr[n][0];
}