#include <iostream>

using namespace std;

int arr[1001][1001];
string s1, s2;

int main() {
	cin >> s1 >> s2;

	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s1[j-1] == s2[i-1]) {
				arr[j][i] = arr[j - 1][i - 1] + 1;
			}
			else {
				arr[j][i] = max(arr[j - 1][i], arr[j][i - 1]);
			}
		}
	}

	cout << arr[s1.size()][s2.size()];
}