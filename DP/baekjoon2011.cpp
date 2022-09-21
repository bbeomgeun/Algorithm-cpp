#include <iostream>
using namespace std;

#define mod 1000000

int dp[5001][2];
string s;

int main() {
	cin >> s;

	dp[0][0] = 1;

	int result = s.size() - 1;

	if (s[0] - '0' == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] - '0' <= 2) { // 결합 가능
			if (s[i] - '0' == 0) {
				dp[i][1] = (dp[i - 1][0]) % mod; // 0이면 결합만 생기므로 [1]으로 옮겨주기만 한다.
				if (s[i - 1] - '0' == 0) {
					cout << 0;
					return 0;
				}
			}
			else {
				if (s[i - 1] - '0' == 2 && s[i] - '0' >= 7) { // 결합불가
					dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
				}
				else {
					dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod; // 기존 단어들에 새롭게 단어 추가
					dp[i][1] = (dp[i - 1][0]) % mod;//([1]으로 갯수를 추가로 더해준다)
				}
			}
		}
		else {
			if (s[i] - '0' == 0) { // 결합도 안되고 0에 해당되는 단어도 없다. 단어 생성 불가 50의 경우
				cout << 0;
				return 0;
			}
			else { // 아니면 기존의 단어들에 뒤에 붙기만 하므로 [0]에 더해준다.
				dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
			}
		}
	}

	cout << (dp[result][0] + dp[result][1]) % mod;
}