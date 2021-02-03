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
		if (s[i - 1] - '0' <= 2) { // ���� ����
			if (s[i] - '0' == 0) {
				dp[i][1] = (dp[i - 1][0]) % mod; // 0�̸� ���ո� ����Ƿ� [1]���� �Ű��ֱ⸸ �Ѵ�.
				if (s[i - 1] - '0' == 0) {
					cout << 0;
					return 0;
				}
			}
			else {
				if (s[i - 1] - '0' == 2 && s[i] - '0' >= 7) { // ���պҰ�
					dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
				}
				else {
					dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod; // ���� �ܾ�鿡 ���Ӱ� �ܾ� �߰�
					dp[i][1] = (dp[i - 1][0]) % mod;//([1]���� ������ �߰��� �����ش�)
				}
			}
		}
		else {
			if (s[i] - '0' == 0) { // ���յ� �ȵǰ� 0�� �ش�Ǵ� �ܾ ����. �ܾ� ���� �Ұ� 50�� ���
				cout << 0;
				return 0;
			}
			else { // �ƴϸ� ������ �ܾ�鿡 �ڿ� �ٱ⸸ �ϹǷ� [0]�� �����ش�.
				dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
			}
		}
	}

	cout << (dp[result][0] + dp[result][1]) % mod;
}